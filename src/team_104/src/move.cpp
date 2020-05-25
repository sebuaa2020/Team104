#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#define go_times 1000000
#define stop_time 1000000
#include <iostream>
#include <stdlib.h>
#include <std_msgs/String.h>
#include <sensor_msgs/LaserScan.h>
#include <sstream>
using namespace std;

double str2double(string s);
int slow(ros::Subscriber scan_sub);
void scanCallback(const sensor_msgs::LaserScan::ConstPtr& msg);//slow
int status_check(geometry_msgs::Twist vel_cmd);
int slow_flag;
int main(int argc, char** argv) {

	ros::init(argc, argv, "move");
	ros::NodeHandle n;
	ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
	ros::Subscriber scan_sub = n.subscribe("/scan",1000,scanCallback);
	ros::Publisher move_error_pub = n.advertise<std_msgs::String>("move_error", 1000);
	ros::Rate loopRate(10);
    if(argc != 7){
        cout<<"argument count error!!! the number is: ,"<<argc - 1;
        if(argc>7){
            cout<<"bigger";
        }else{
            cout<<"smaller";
        }

        cout<< "than 6." <<endl;
    }
    //int times = go_times;
	int times = 5;

	while(ros::ok()&&times>0) {

		geometry_msgs::Twist vel_cmd;

		vel_cmd.linear.x = str2double(string(argv[1]));
		vel_cmd.linear.y = str2double(string(argv[2]));
		vel_cmd.linear.z = str2double(string(argv[3]));

		vel_cmd.angular.x = str2double(string(argv[4]));
		vel_cmd.angular.y = str2double(string(argv[5]));
		vel_cmd.angular.z = str2double(string(argv[6]));
		if (status_check(vel_cmd)) {
            times = 0;
            std_msgs::String err_msg;
            std::stringstream ss;
            ss<<"MOVE STATUS ERROR"<<cout;
            err_msg.data = ss.str();
            move_error_pub.publish(err_msg);
            break;
		}
		if (slow_flag) {
            vel_cmd.linear.x = vel_cmd.linear.x/2;
            vel_cmd.linear.y = vel_cmd.linear.y/2;
            vel_cmd.linear.z = vel_cmd.linear.z/2;
            slow_flag = 0;
		}
		vel_pub.publish(vel_cmd);
        times--;

		loopRate.sleep();
		//ros::spinOnce();
	}


    //times = stop_time;
	times = 5;

	while(ros::ok()&&times>0) {

		geometry_msgs::Twist vel_cmd;

		vel_cmd.linear.x = 0;
		vel_cmd.linear.y = 0;
		vel_cmd.linear.z = 0;

		vel_cmd.angular.x = 0;
		vel_cmd.angular.y = 0;
		vel_cmd.angular.z = 0;
		vel_pub.publish(vel_cmd);

        times--;

		loopRate.sleep();
		//ros::spinOnce();
	}

    return 0;

}
int slow(double range_min){
    if (range_min <= 0.1)
        return 1;
    return 0;
}
void scanCallback(const sensor_msgs::LaserScan::ConstPtr& msg)//slow
 {
    slow_flag = slow(msg->range_min);
    //^
 }
int status_check(geometry_msgs::Twist vel_cmd){
    if((vel_cmd.linear.x || vel_cmd.linear.y || vel_cmd.linear.z || vel_cmd.angular.x || vel_cmd.angular.y || vel_cmd.angular.z)==0){
        cout<< "status error: movement massage is valid." <<endl;
        return 1;
    }
    return 0;
}
double str2double(string s){
    return atof(s.c_str());
}
