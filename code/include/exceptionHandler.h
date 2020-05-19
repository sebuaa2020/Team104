#ifndef EXCEPTIONHANDLER
#define EXCEPTIONHANDLER
#include "wpb_home_tutorials/Follow.h"
#include "xfyun_waterplus/IATSwitch.h"
#include <actionlib/client/simple_action_client.h>
#include <bits/stdc++.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Twist.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <ros/ros.h>
#include <sound_play/SoundRequest.h>
#include <std_msgs/String.h>
#include <tf/transform_listener.h>
#include <waterplus_map_tools/GetWaypointByName.h>
#include <waterplus_map_tools/Waypoint.h>
using namespace std;
namespace exceptionHandler {
string message;
ros::Publisher spk_pub;
sound_play::SoundRequest spk_msg;
void speak(string s);
string getMessage();
void speechException(string in);
void autoExecption(string in);
void grabFailedException(string in);
void mapFailedException(string in);
void targetFailedException(string in);
void timeLimitedException(string in);
}
#endif