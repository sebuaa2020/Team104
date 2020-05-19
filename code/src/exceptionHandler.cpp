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
    message = "speech exception," + in;
    speak(message);
}
void autoExecption(string in)
{
    message = "auto exception, " + in;
    speak(message);
}
void grabFailedException(string in)
{
    message = "grab failed exception, " + in;
    speak(message);
}
void mapFailedException(string in)
{
    message = "map failed exception, " + in;
    speak(message);
}
void targetFailedException(string in)
{
    message = "target failed exception, " + in;
    speak(message);
}
void timeLimitedException(string in)
{
    message = "time limited exception, " + in;
    speak(message);
}
}