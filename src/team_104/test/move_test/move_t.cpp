#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "exceptionHandler.cpp"
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
int main_(int argc, char **argv, double lx, double ly, double lz, double rx, double ry, double rz,double t);
int main(int argc, char** argv)
{
    if(argc<3)
    {
    	puts("23");
        exceptionHandler::otherError("the number of arguments is smaller than 2");
        assert(0);
    }
    else if(argc>3)
    {
    	puts("29");
        exceptionHandler::otherError("the number of arguments is bigger than 2");
        assert(0);
    }
    string cmd=(string)argv[1];
    double arg=str2double((string)(argv[2]));
    if(arg<0)
    {
    	puts("37");
        exceptionHandler::otherError("Argument must be positive");
        assert(0);
    }
    double pi=acos(-1);
    double t;
    double v;
    if(cmd=="forward"||cmd=="backward"||cmd=="left"||cmd=="right")
    {
    	puts("46");
        v=0.3;
        t=arg/v;
        if(arg>5)
        {
            exceptionHandler::otherError("Can't move so fast!");
            assert(0);
        }
    }
    else if(cmd=="rotate_l"||cmd=="rotate_r")
    {
    	puts("57");
        if(arg>180)
        {
            exceptionHandler::otherError("Can't rotate so fast");
            assert(0);
        }
        v=15*pi/180;
        t=arg*pi/180/v;
    } else if(cmd=="stop")
    {
    	puts("67");
        v=0,t=3;
    }
    else 
    {
    	puts("72");
        exceptionHandler::cmdErrorException("");
        assert(0);
    }
    if(cmd=="forward")
    	puts("77"),main_(argc,argv,v,0,0,0,0,0,t);
    else if(cmd=="backward")
        puts("79"),main_(argc,argv,-v,0,0,0,0,0,t);
    else if(cmd=="left")
        puts("81"),main_(argc,argv,0,v,0,0,0,0,t);
    else if(cmd=="right")
        puts("83"),main_(argc,argv,0,-v,0,0,0,0,t);
    else if(cmd=="rotate_l")
        puts("85"),main_(argc,argv,0,0,0,0,0,v,t);
    else if(cmd=="rotate_r")
        puts("87"),main_(argc,argv,0,0,0,0,0,-v,t);
    else puts("88"),main_(argc,argv,0,0,0,0,0,0,t);
}
int main_(int argc, char **argv, double lx, double ly, double lz, double rx, double ry, double rz,double t) {

	ros::init(argc, argv, "move");
	ros::NodeHandle n;
	ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
	ros::Subscriber scan_sub = n.subscribe("/scan",1000,scanCallback);
	ros::Publisher move_error_pub = n.advertise<std_msgs::String>("move_error", 1000);
	ros::Rate loopRate(10);
    //int times = go_times;
	int times = t;

	while(ros::ok()&&times>0) {

		geometry_msgs::Twist vel_cmd;

		vel_cmd.linear.x = lx;//str2double(string(argv[1]));
		vel_cmd.linear.y = ly;//str2double(string(argv[2]));
		vel_cmd.linear.z = lz;//str2double(string(argv[3]));

		vel_cmd.angular.x = rx;//str2double(string(argv[4]));
		vel_cmd.angular.y = ry;//str2double(string(argv[5]));
		vel_cmd.angular.z = rz;//str2double(string(argv[6]));
		/*if (status_check(vel_cmd)) {
            times = 0;
            std_msgs::String err_msg;
            std::stringstream ss;
            ss<<"MOVE STATUS ERROR"<<cout;
            err_msg.data = ss.str();
            move_error_pub.publish(err_msg);
            break;
		}*/
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

/*
    //times = stop_time;
	times = 2;

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
*/
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
