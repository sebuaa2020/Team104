#include "speech.h"
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/String.h>

static ros::Publisher vel_pub;
void KeywordCB(const std_msgs::String::ConstPtr & msg)
{
    ROS_WARN("[KeywordCB] - %s",msg->data.c_str());
    //运动类指令
    geometry_msgs::Twist vel_cmd;
    vel_cmd.linear.x = 0;
    vel_cmd.linear.y = 0;
    vel_cmd.linear.z = 0;
    vel_cmd.angular.x = 0;
    vel_cmd.angular.y = 0;
    vel_cmd.angular.z = 0;

    int nFindIndex = 0;
    bool isMove = false;
    nFindIndex = msg->data.find("Forward");
    if(nFindIndex >= 0)
    {
        vel_cmd.linear.x = 0.1;
	isMove = true;
    }
    nFindIndex = msg->data.find("Backward");
    if(nFindIndex >= 0)
    {
        vel_cmd.linear.x = -0.1;
	isMove = true;
    }
    nFindIndex = msg->data.find("Left");
    if(nFindIndex >= 0)
    {
        vel_cmd.linear.y = 0.1;
	isMove = true;
    }
    nFindIndex = msg->data.find("Right");
    if(nFindIndex >= 0)
    {
        vel_cmd.linear.y = -0.1;
	isMove = true;
    }
    nFindIndex = msg->data.find("Stop");
    if(nFindIndex >= 0)
    {
        vel_cmd.linear.x = 0;
        vel_cmd.linear.y = 0;
        vel_cmd.angular.z = 0;
	isMove = true;
    }
    if (isMove) vel_pub.publish(vel_cmd);
    //地点关键词
    nFindIndex = msg->data.find("Master");
    if(nFindIndex >= 0)
    {
	//标记用户所在位置
    }
    nFindIndex = msg->data.find("Place N");
    if(nFindIndex >= 0)
    {
	//标记地点关键点N
    }
    //跟随指令
    nFindIndex = msg->data.find("Follow");
    if(nFindIndex >= 0)
    {
	//命令机器人跟随管理员
    }
    nFindIndex = msg->data.find("Stop Follow");
    if(nFindIndex >= 0)
    {
	//命令机器人停止跟随
    }


}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "wpb_home_voice_cmd");

    ros::NodeHandle n;
    vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    ros::Subscriber sub_sr = n.subscribe("/recognizer/output", 10, KeywordCB);

    ros::spin();

    return 0;
}
