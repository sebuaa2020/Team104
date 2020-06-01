#include "controller.h"
#include "exceptionHandler.cpp"
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/String.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_listener.h>
#include <visualization_msgs/Marker.h>
#include <waterplus_map_tools/Waypoint.h>
#include <waterplus_map_tools/GetNumOfWaypoints.h>
#include <waterplus_map_tools/GetWaypointByIndex.h>
#include <waterplus_map_tools/GetWaypointByName.h>
#include <string>
using namespace std;
namespace STATE {
bool state[5] = { 0 };
const int _started = 0;
const int _navigation = 1;
const int _gmapping = 2;
const int _keyboard = 3;
}
namespace controller {
class waypoint {
public:
    string name;
    float x;
    float y;
};
waypoint waypointArray[10];
string s, t;
bool getstate(string s)
{
    using namespace STATE;
    if (s == (string)("started"))
        return state[_started];
    else if (s == (string)("navigation"))
        return state[_navigation];
    else if (s == (string)("gmapping"))
        return state[_gmapping];
    else if (s == (string)("keyboard"))
        return state[_keyboard];
    else
        assert(0);
}
void setstate(string s, bool bo)
{
    using namespace STATE;
    if (s == (string)("started"))
        state[_started] = bo;
    else if (s == (string)("navigation"))
        state[_navigation] = bo;
    else if (s == (string)("gmapping"))
        state[_gmapping] = bo;
    else if (s == (string)("keyboard"))
        state[_keyboard] = bo;
    else
        assert(0);
}

void start()
{
    int ret = system("gnome-terminal -x roslaunch robot_sim_demo robot_spawn.launch");
    if (ret != -1 || ret != 127) {
        puts("robot starting!");
        setstate("started", 1);
    } else {
        exceptionHandler::cmdErrorException("started failed");
    }
}

void gmapping()
{
    int ret = system("gnome-terminal -x roslaunch team_104 gmapping.launch");
    if (ret != -1 || ret != 127) {
        cout << "gmapping_start,please use keyboard to controll" << endl;
        setstate("gmapping", 1);
	ret = system("gnome-terminal -x roslaunch wpb_home_tutorials hector_mapping.launch");
	if (ret != -1 || ret != 127) {
            cout << "slam_start,please uwaypointArray[10];se keyboard to controll" << endl;
	} 
    } else {
        exceptionHandler::cmdErrorException("start gmapping failed");
    }
}

void saveMap()
{
    int ret = system("rosrun map_server map_saver -f  ./src/team_104/maps/map");
    if (ret != -1 || ret != 127) {
        puts("map saved");
        setstate("gmapping", 0);
    } else {
        exceptionHandler::cmdErrorException("map saved failed");
    }
}
void keyboardControll()
{
    int ret = system("gnome-terminal -x rosrun team_104 keyboard");
    if (ret != -1 || ret != 127) {
        puts("start control by keyboard");
    } else {
        exceptionHandler::cmdErrorException("start control by keyboard failed");
    }
}
void navigation()
{
    int ret = system("gnome-terminal -x roslaunch team_104 nav_initial_set.launch");
    if (ret != -1 || ret != 127) {
        puts("navigation start!");
    } else {
        exceptionHandler::cmdErrorException("navigation failed");
    }
}
void setPoint(string x, string y)
{   
    string str = "gnome-terminal -x rosrun team_104 navigate " + x + " " + y;
    int ret = system(str.data());
    if (ret != -1 || ret != 127) {
        cout << "point set, start move!" << endl;
    } else {
        exceptionHandler::cmdErrorException("set point failed");
    }
}
void speech()
{
    string str = "gnome-terminal -x roslaunch xfyun_waterplus iat_en.launch";
    int ret = system(str.data());
    if (ret != -1 || ret != 127) {
        cout << "speak!" << endl;
    } else {
        exceptionHandler::cmdErrorException("speech failed");
    }
    
}


void KeywordCB(const std_msgs::String::ConstPtr & msg)
{
    ROS_WARN("[KeywordCB] - %s",msg->data.c_str());
    s = msg->data.c_str();
    ros::shutdown();
}
}
int main(int argc,char** argv)
{
    puts("robot started!\nplease type in and instruction:");
    while (1) {
        puts("1: 启动\n2: 开始建图\n3: 保存地图\n4: 手动控制移动\n5: 导航\n6: 设定地点");

        int input;
        scanf("%d", &input);
        if (input == 1) {
            if (controller::getstate("started")) {
                puts("already started, don't need to start again!");
            } else
                controller::start();
        } else if (input == 2) {
            if (!controller::getstate("keyboard")) {
                puts("now first starting keyboard!");
                controller::keyboardControll();
            }
            controller::gmapping();
        } else if (input == 3) {
            if (!controller::getstate("gmapping"))
                puts("I can't save map without gampping first!");
            else
                controller::saveMap();
        } else if (input == 4) {
            controller::keyboardControll();
        } else if (input == 5) {
            controller::navigation();
        } else if (input == 6) {
            string str = "gnome-terminal -x roslaunch waterplus_map_tools wpb_home_nav_test.launch";
            system(str.data());
            puts("1: 键入目标地图坐标   2: 键入目标名字    3: 启用语音输入目标名字\n");
            //目标点表
            scanf("%d",&input);
            if(input != 1){              
                ros::init(argc, argv, "controller");
                ros::NodeHandle nh;
                ros::ServiceClient cliGetNum = nh.serviceClient<waterplus_map_tools::GetNumOfWaypoints>("/waterplus/get_num_waypoint");
                ros::ServiceClient cliGetWPIndex = nh.serviceClient<waterplus_map_tools::GetWaypointByIndex>("/waterplus/get_waypoint_index");
                ros::ServiceClient cliGetWPName = nh.serviceClient<waterplus_map_tools::GetWaypointByName>("/waterplus/get_waypoint_name");
                waterplus_map_tools::GetNumOfWaypoints srvNum;
                waterplus_map_tools::GetWaypointByIndex srvI;
                int waypointNum = 0;
                if (cliGetNum.call(srvNum)) {
                    ROS_INFO("Num_wp = %d", (int)srvNum.response.num);
                }
                else {
                    ROS_ERROR("Failed to call service get_num_waypoints");
                }
                for(int i=0;i<srvNum.response.num;i++) {
                    srvI.request.index = i;
                    if (cliGetWPIndex.call(srvI)) {
                        std::string name = srvI.response.name;
                        float x = srvI.response.pose.position.x;
                        float y = srvI.response.pose.position.y;
                        controller::waypointArray[i].name = name;
                        controller::waypointArray[i].x = x;
                        controller::waypointArray[i].x = y;
                        waypointNum++;
                    } else {
                        puts("Failed to call service get_wp_index");
                    }
                }
                cout << waypointNum <<endl;
                for (int i = 0;i < waypointNum;i++) {
                    cout<<i<<endl;
                    cout << "    name:" << controller::waypointArray[i].name <<  endl;
                    cout << "    x:" << controller::waypointArray[i].x <<  endl;
                    cout << "    y:" << controller::waypointArray[i].y <<  endl;

                }
                puts("type in the point you want to set!");
            }
            if(input == 1){
                puts("type in the point you want to set!");
                cin >> controller::s;
                cin >> controller::t;
                controller::setPoint(controller::s, controller::t);
            } else if(input == 2){
                cin >> controller::s;
                controller::setPoint(controller::s,"");
            } else if(input == 3){
                puts("speak the name of target point in 10s\n");
                ros::init(argc, argv, "wpb_home_voice_cmd");
                ros::NodeHandle nh;
                controller::speech();
                ros::Subscriber sub_sr = nh.subscribe("/xfyun/iat", 10, controller::KeywordCB);
                ros::spin();
                controller::setPoint(controller::s,""); 
            }
            
        } else {
            puts("there's no other cmds except 1~6!");
        }
    }
    return 0;
}
