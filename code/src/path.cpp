#include <ros/ros.h> 
#include <move_base_msgs/MoveBaseAction.h> 
#include <actionlib/client/simple_action_client.h> 
#include "exceptionHandler.h"
using namespace std;
 
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient; 

void avoidObstacle(){
	return;
}

int main(int argc,char **argv){
	ros::init(argc, argv, "pathPlanning");
	MoveBaseClient ac("move_base", true);
	
	while(!ac.waitForServer(ros::Duration(5.0))){
	    ROS_INFO("Waiting for the move_base action server to come up");   
	}
	
	move_base_msgs::MoveBaseGoal goal;
	goal.target_pose.header.frame_id = "base_footprint"; 
	goal.target_pose.header.stamp = ros::Time::now();
	goal.target_pose.pose.position.x = getPositionX(); 
	goal.target_pose.pose.orientation.w = getPositionY();
	
	ROS_INFO("Sending goal"); 
	ac.sendGoal(goal); 
    ac.waitForResult();
    
    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    	ROS_INFO("The base moved 1 meter forward");
	} else{
		ROS_INFO("The base failed to move forward 1 meter");
		targetFailedException();
	} 
 
  return 0;
}

