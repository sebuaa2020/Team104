#include <ros/ros.h>
#include <stdlib.h>
#include <iostream>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
/*move_base_msgs::MoveBaseAction
 move_base在world中的目标
*/ 
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>  MoveBaseClient;
using namespace std;

int main(int argc, char** argv) {
    ros::init(argc, argv, "navigation_interface_node");
    MoveBaseClient ac("move_base", true);
 
    // Wait 60 seconds for the action server to become available
    ROS_INFO("Waiting for the move_base action server");
    ac.waitForServer(ros::Duration(60));
    ROS_INFO("Connected to move base server");
 
    // Send a goal to move_base
    //目标的属性设置
    move_base_msgs::MoveBaseGoal goal;
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now(); //设置导航点
    double x,y;

    if (argc == 2){

    }else if(argc == 3){
        x = strtod(argv[1],NULL);
        y = strtod(argv[2],NULL);
        goal.target_pose.pose.position.x = x;
        goal.target_pose.pose.position.y = y;
        goal.target_pose.pose.orientation.w = 1;
        ROS_INFO("Sending goal");
        ac.sendGoal(goal);
        // Wait for the action to return
        ac.waitForResult();
        if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
        {   ROS_INFO("You have reached the goal!");
            return 0;
        }
        else
        ROS_INFO("The base failed for some reason");
        return 0;
    }else{
        cout<<"too many argc!!!!!"<<endl;
    }
        
}