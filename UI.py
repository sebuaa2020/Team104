import tkinter as tk
import subprocess as sp
import pickle
import time
import os

top = tk.Tk()
top.title("机器人，你在干神魔？")
top.geometry("1080x720")
_login = False
welcome = tk.Label(top, text='欢迎使用 餐厅简易服务机器人', bg='#A0A4FF', font=('consolas', 15), width=1080, height=2)
welcome.pack()
team = tk.Label(top, text='BUAA team: 104', font=('consolas', 10), height=1)
team.place(x=970, y=700)

message = tk.StringVar()
message.set('please login!')
output_window = tk.Label(top, textvariable=message, bg='#FFFFFF', font=('consolas', 12), width=50, height=15)
output_window.place(x=80, y=280)

_started = False
_navigation = False
_gmapping = False
_keyboard = False
_detection = False

gazebo_m = tk.StringVar()
navigation_m = tk.StringVar()
gmapping_m = tk.StringVar()
keyboard_m = tk.StringVar()
detection_m = tk.StringVar()
__gazebo = tk.Label(top, textvariable=gazebo_m, font=('consolas', 12))
__navigation = tk.Label(top, textvariable=navigation_m, font=('consolas', 12))
__gmapping = tk.Label(top, textvariable=gmapping_m, font=('consolas', 12))
__keyboard = tk.Label(top, textvariable=keyboard_m, font=('consolas', 12))
__detection = tk.Label(top, textvariable=detection_m, font=('consolas', 12))
gazebo_m.set("gazebo    : off")
navigation_m.set("navigation: off")
gmapping_m.set("gmapping  : off")
keyboard_m.set("keyboard  : off")
detection_m.set("detection : off")

start_p = None


def start():
    global _started, start_p
    if _started:
        start_p.kill()
        _started = False
        gazebo_m.set("gazebo    : off")
        return
    sp.Popen("roslaunch robot_sim_demo robot_spawn.launch", shell=True)
    message.set("gazebo starting!\nplease wait {} seconds".format(10))
    # message.set("gazebo started.")
    gazebo_m.set("gazebo    : on")
    _started = True


def gmapping():
    global _gmapping
    sp.Popen("roslaunch wpb_home_tutorials gmapping.launch", shell=True)
    message.set("gmapping starting!\nplease wait {} seconds".format(5))
    sp.Popen("roslaunch wpb_home_tutorials hector_mapping.launch", shell=True)
    _gmapping = True
    gmapping_m.set("gmapping  : on")


def savemap():
    global _gmapping
    if not _gmapping:
        message.set("please start gmapping first!")
        return
    sp.Popen("rosrun map_server map_saver -f  ./src/team_104/maps/map", shell=True)
    message.set("map saved")
    _gmapping = False
    gmapping_m.set("gmapping  : off")


keyboard_p = None


def keyboard():
    global _keyboard, keyboard_p
    if _keyboard:
        keyboard_p.kill()
        _keyboard = False
        keyboard_m.set("keyboard  : off")
        return
    keyboard_p = sp.Popen("gnome-terminal -x rosrun team_104 keyboard", shell=True, stdin=sp.PIPE)
    message.set("keyboard controller started!\n please click buttons to controll the robot.")
    _keyboard = True
    keyboard_m.set("keyboard  : on")


user = {}
if os.path.exists('users.pkl'):
    with open('users.pkl', 'rb') as f:
        user = pickle.load(f)
Username = tk.StringVar()
username_string = tk.Label(top, text='Username:', font=('consolas', 13))
username_string.place(x=100, y=80)
password_string = tk.Label(top, text='Password:', font=('consolas', 13))
password_string.place(x=100, y=120)
username = tk.Entry(top, show=None, font=("consolas", 13))
password = tk.Entry(top, show="*", font=("consolas", 13))
username.place(x=200, y=80)
password.place(x=200, y=120)


def forward():
    if not _keyboard:
        message.set("please first start the keyboard controller!")
        return
    keyboard_p.stdin.write(b"i")
    keyboard_p.stdin.flush()


def backward():
    if not _keyboard:
        message.set("please first start the keyboard controller!")
        return
    keyboard_p.stdin.write(b"k")
    keyboard_p.stdin.flush()


def left():
    if not _keyboard:
        message.set("please first start the keyboard controller!")
        return
    keyboard_p.stdin.write(b"u")
    keyboard_p.stdin.flush()


def right():
    if not _keyboard:
        message.set("please first start the keyboard controller!")
        return
    keyboard_p.stdin.write(b"o")
    keyboard_p.stdin.flush()


buttons = []

gazebo_start = tk.Button(top, text="gazebo on/off", font=("consolas", 14), command=start)
buttons.append([gazebo_start, 230, 600])
keyboard_start = tk.Button(top, text="keyboard on/off", font=("consolas", 14), command=keyboard)
buttons.append([keyboard_start, 600, 130])
forward = tk.Button(top, text="前", font=("consolas", 14), command=forward)
# buttons.append([forward, 870, 70])
backward = tk.Button(top, text="后", font=("consolas", 14), command=backward)
# buttons.append([backward, 870, 130])
left = tk.Button(top, text="左", font=("consolas", 14), command=left)
# buttons.append([left, 800, 130])
right = tk.Button(top, text="右", font=("consolas", 14), command=right)
# buttons.append([right, 940, 130])

gmapping = tk.Button(top, text="gmapping on/off", font=("consolas", 14), command=gmapping)
buttons.append([gmapping, 600, 230])
savemap = tk.Button(top, text="save map", font=("consolas", 14), command=savemap)
buttons.append([savemap, 870, 230])

detection_p = None


def detection():
    global _detection, detection_p
    if _detection:
        _detection = False
        detection_p.kill()
        detection_m.set("detection : off")
        return
    detection_p = sp.Popen("roslaunch wpb_home_tutorials obj_detect.launch", shell=True)
    _detection = True
    detection_m.set("detection : on")
    message.set("rviz starting!")


# detection = tk.Button(top, text="detection on/off", font=("consolas", 14), command=detection)
# buttons.append([detection, 600, 430])

def newpoint():
    sp.Popen("roslaunch waterplus_map_tools add_waypoint.launch", shell=True)


newpoint = tk.Button(top, text="new point", font=("consolas", 14), command=newpoint)
buttons.append([newpoint, 600, 430])

_grab = False


def grab():
    global _grab
    if not _detection:
        message.set("please start detection first!")
        return
    if _grab:
        message.set("already grab!")
        return
    _grab = True
    message.set("grab successfully!")


# grab = tk.Button(top, text="grab", font=("consolas", 14), command=grab)
# buttons.append([grab, 800, 430])


def putdown():
    global _grab
    if not _grab:
        message.set("please grab a item first!")
        return
    _grab = True
    message.set("put down successfully!")


# putdown = tk.Button(top, text="put down", font=("consolas", 14), command=putdown)
# buttons.append([putdown, 900, 430])
def savepoint():
    sp.Popen("rosrun waterplus_map_tools wp_saver", shell=True)


savepoint = tk.Button(top, text="save point", font=("consolas", 14), command=savepoint)
buttons.append([savepoint, 900, 430])

navigation_p = None


def navigation():
    global _navigation, navigation_p
    if not _navigation:
        navigation_p = sp.Popen("rosrun team_104 controller", shell=True, stdin=sp.PIPE, stdout=sp.PIPE)
    # navigation_p.stdout.readlines()
    navigation_p.stdin.write(b"6\n")
    navigation_p.stdin.flush()
    # if not _navigation:
    #    sp.Popen("rosrun team_104 setPosition", shell=True)
    message.set("navigation controller started!\n please click buttons to choose the functions.")
    _navigation = True
    navigation_m.set("navigation: on")
    navigation.place_forget()
    navigation_1.place(x=600, y=330)
    navigation_2.place(x=750, y=330)
    navigation_3.place(x=900, y=330)


navigation = tk.Button(top, text="navigation", font=("consolas", 14), command=navigation)
buttons.append([navigation, 600, 330])


def navigation_1():
    navigation_p.stdin.write(b"1\n")
    navigation_p.stdin.flush()
    message.set("please input the coordinate of target")
    navigation_1.place_forget()
    navigation_2.place_forget()
    navigation_3.place_forget()
    _navigation_x.place(x=600, y=330)
    _navigation_y.place(x=750, y=330)
    navigation_x.place(x=630, y=330)
    navigation_y.place(x=780, y=330)
    navigation_1_start.place(x=900, y=325)


navigation_1 = tk.Button(top, text="input", font=("consolas", 14), command=navigation_1)
navigation_x = tk.Entry(top, show=None, font=("consolas", 14), width=10)
_navigation_x = tk.Label(top, text='x:', font=('consolas', 14))
navigation_y = tk.Entry(top, show=None, font=("consolas", 14), width=10)
_navigation_y = tk.Label(top, text='y:', font=('consolas', 14))


def navigation_1_start():
    xy = navigation_x.get().encode() + b"\n" + navigation_y.get().encode() + b"\n"
    navigation_p.stdin.write(xy)
    navigation_p.stdin.flush()
    navigation_x.place_forget()
    navigation_y.place_forget()
    _navigation_x.place_forget()
    _navigation_y.place_forget()
    navigation_1_start.place_forget()
    navigation.place(x=600, y=330)


navigation_1_start = tk.Button(top, text="start", font=("consolas", 14), command=navigation_1_start)


def get_navi():
    import xml.dom.minidom as dd
    dom = dd.parse('./src/team_104/maps/waypoints.xml')
    ddd = dom.getElementsByTagName("Waypoint")
    ret = ""
    for x in ddd:
        ret += "name: " + x.getElementsByTagName("Name")[0].childNodes[0].data + "\n"
        ret += "x: " + x.getElementsByTagName("Pos_x")[0].childNodes[0].data + "\n"
        ret += "y: " + x.getElementsByTagName("Pos_y")[0].childNodes[0].data + "\n"
        ret += "\n"
    message.set(ret.encode())


def navigation_2():
    navigation_p.stdin.write(b"2\n")
    navigation_p.stdin.flush()
    message.set("please input the number of target")
    get_navi()
    navigation_1.place_forget()
    navigation_2.place_forget()
    navigation_3.place_forget()
    _navigation_num.place(x=600, y=330)
    navigation_num.place(x=680, y=330)
    navigation_2_start.place(x=900, y=325)


navigation_2 = tk.Button(top, text="choice", font=("consolas", 14), command=navigation_2)

navigation_num = tk.Entry(top, show=None, font=("consolas", 14))
_navigation_num = tk.Label(top, text='number:', font=('consolas', 14))


def navigation_2_start():
    xy = navigation_num.get().encode() + b"\n"
    navigation_p.stdin.write(xy)
    navigation_p.stdin.flush()
    navigation_num.place_forget()
    _navigation_num.place_forget()
    navigation_2_start.place_forget()
    navigation.place(x=600, y=330)


navigation_2_start = tk.Button(top, text="start", font=("consolas", 14), command=navigation_2_start)


def navi_ret():
    navigation.place(x=600, y=330)
    navi_ret.place_forget()
    _navigation_tell.place_forget()


navi_ret = tk.Button(top, text="return", font=("consolas", 14), command=navi_ret)


def navigation_3():
    navigation_p.stdin.write(b"3\n")
    navigation_p.stdin.flush()
    message.set("please tell me the name of target")
    get_navi()
    navigation_1.place_forget()
    navigation_2.place_forget()
    navigation_3.place_forget()
    _navigation_tell.place(x=600, y=330)
    navi_ret.place(x=1000, y=325)


navigation_3 = tk.Button(top, text="speak", font=("consolas", 14), command=navigation_3)
_navigation_tell = tk.Label(top, text='please tell me the number of target', font=('consolas', 14))


def login():
    u = username.get()
    p = password.get()
    if not u in user:
        message.set("Invalid username!")
    elif user[u] != p:
        message.set("Wrong password!")
    else:
        Username.set(u)
        username_string.place_forget()
        password_string.place_forget()
        username.place_forget()
        password.place_forget()
        login.place_forget()
        register.place_forget()
        w = tk.Label(top, text='Welcome! ', font=('consolas', 14))
        w.place(x=100, y=75)
        n = tk.Label(top, textvariable=Username, font=('consolas', 14))
        n.place(x=200, y=100)
        message.set('robot started!\nplease click the buttons.')
        __gazebo.place(x=100, y=130)
        __navigation.place(x=100, y=160)
        __gmapping.place(x=100, y=190)
        __keyboard.place(x=100, y=220)
        __detection.place(x=100, y=250)

        _login = True

        for b, x, y in buttons:
            b.place(x=x, y=y)


def register():
    u = username.get()
    p = password.get()
    if u in user:
        message.set("there is another user has this name!")
    else:
        user[u] = p
        message.set("register successfully!")
        with open('users.pkl', 'wb') as f:
            pickle.dump(user, f, pickle.HIGHEST_PROTOCOL)


login = tk.Button(top, text="login", font=('consolas', 14), command=login)
login.place(x=200, y=160)
register = tk.Button(top, text="register", font=('consolas', 14), command=register)
register.place(x=280, y=160)

if __name__ == "__main__":
    top.mainloop()
