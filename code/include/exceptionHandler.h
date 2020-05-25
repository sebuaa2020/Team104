#ifndef EXCEPTIONHANDLER
#define EXCEPTIONHANDLER
#include <bits/stdc++.h>
#include <ros/ros.h>
#include <sound_play/SoundRequest.h>
#include <std_msgs/String.h>
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