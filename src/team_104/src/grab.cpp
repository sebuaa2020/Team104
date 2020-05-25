#include "grab.h"
#include <ros/ros.h>
#include <std_msgs/String.h>

static ros::Publisher behaviors_pub;
static std_msgs::String behavior_msg;

void GrabResultCB(const std_msgs::String::ConstPtr &msg)
{
    ROS_WARN("[GrabResultCB] %s",msg->data.c_str());
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "wpb_home_grab_client");  //程序初始化

    ros::NodeHandle n;
    behaviors_pub = n.advertise<std_msgs::String>("/wpb_home/behaviors", 30);
    ros::Subscriber res_sub = n.subscribe("/wpb_home/grab_result", 30, GrabResultCB);

    ROS_WARN("[main] wpb_home_grab_client");
    sleep(1);

    behavior_msg.data = "grab start";
    behaviors_pub.publish(behavior_msg);

    ros::Rate r(30);
    while(ros::ok())
    {
        ros::spinOnce();
        r.sleep();
    }

    return 0;
}
