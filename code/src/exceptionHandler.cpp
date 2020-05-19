#include "exceptionHandler.h"
namespace exceptionHandler {
void speak(string s)
{
    spk_msg.arg = s;
    spk_pub.publish(spk_msg);
}
string getMessage()
{
    return message;
}
void speechException(string in)
{
    ROS_INFO("Failed to get instruction from speech");
    message = "speech exception," + in;
    speak(message);
}
void autoExecption(string in)
{
    ROS_INFO("Failed to get instruction during auto behavier");
    message = "auto exception, " + in;
    speak(message);
}
void grabFailedException(string in)
{
    ROS_INFO("Failed to grab things");
    message = "grab failed exception, " + in;
    speak(message);
}
void mapFailedException(string in)
{
    ROS_INFO("Failed to establish a map");
    message = "map failed exception, " + in;
    speak(message);
}
void targetFailedException(string in)
{
    ROS_INFO("Failed to walk to the target");
    message = "target failed exception, " + in;
    speak(message);
}
void timeLimitedException(string in)
{
    ROS_INFO("Walk time limited error");
    message = "time limited exception, " + in;
    speak(message);
}
}