#include <ros/ros.h>
#include <stdlib.h>
#include <iostream>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <waterplus_map_tools/Waypoint.h>
#include <waterplus_map_tools/GetNumOfWaypoints.h>
#include <waterplus_map_tools/GetWaypointByIndex.h>
#include <waterplus_map_tools/GetWaypointByName.h>
/*move_base_msgs::MoveBaseAction
 move_base在world中的目标
*/ 
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>  MoveBaseClient;
using namespace std;

int main(int argc, char** argv) {
    ros::init(argc, argv, "navigation_interface_node");
    MoveBaseClient ac("move_base", true);
 
    // Wait 50 seconds for the action server to become available
    ROS_INFO("Waiting for the move_base action server");
    ac.waitForServer(ros::Duration(50));
    ROS_INFO("Connected to move base server");
 
    // Send a goal to move_base
    //目标的属性设置
    move_base_msgs::MoveBaseGoal goal;
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now(); //设置导航点
    double x,y;

    if (argc == 2){
    	puts("33");
        ros::NodeHandle nh;
        ros::ServiceClient cliGetNum = nh.serviceClient<waterplus_map_tools::GetNumOfWaypoints>("/waterplus/get_num_waypoint");
        ros::ServiceClient cliGetWPIndex = nh.serviceClient<waterplus_map_tools::GetWaypointByIndex>("/waterplus/get_waypoint_index");
        ros::ServiceClient cliGetWPName = nh.serviceClient<waterplus_map_tools::GetWaypointByName>("/waterplus/get_waypoint_name");
        waterplus_map_tools::GetNumOfWaypoints srvNum;
        waterplus_map_tools::GetWaypointByIndex srvI;
        if (cliGetNum.call(srvNum)) {
    		puts("41");
            ROS_INFO("Num_wp = %d", (int)srvNum.response.num);
        }
        else {
    		puts("45");
            ROS_ERROR("Failed to call service get_num_waypoints");
         }
        int i;
        for(i=0;i<srvNum.response.num;i++) {
            srvI.request.index = i;
            if (cliGetWPIndex.call(srvI)) {
    			puts("52");
                std::string name = srvI.response.name;
                if(name == argv[1]){
    				puts("55");
                    x = srvI.response.pose.position.x;
                    y = srvI.response.pose.position.y;
                    break;
                }
            } else {
    				puts("61");
                puts("Failed to call service get_wp_index");
            }
        }
        if (i == srvNum.response.num) {
    		puts("66");
            cout << "Failed to get the waypoint \"" << argv[1] << "\"" << endl;
            return 0;
        }
        puts("type in the point you want to set!");
        
    }else if(argc == 3){
    	puts("73");
        x = strtod(argv[1],NULL);
        y = strtod(argv[2],NULL);  
    }
    else{
    	puts("78");
        cout<<"too many argc!!!!!"<<endl;
    }

    goal.target_pose.pose.position.x = x;
    goal.target_pose.pose.position.y = y;
    goal.target_pose.pose.orientation.w = 1;
    ROS_INFO("Sending goal");
    ac.sendGoal(goal);
    // Wait for the action to return
    ac.waitForResult();
    if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    {   
    	puts("91");
		ROS_INFO("You have reached the goal!");
        return 0;
    }
    else
    {
    	
    	puts("98");
    	ROS_INFO("The base failed for some reason");
    }
    return 0;    
}
