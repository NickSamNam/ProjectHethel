#ifndef MQTTSUBSCRIBE_H
#define MQTTSUBSCRIBE_H

#include <string>

namespace Networking
{
class MqttSubscribe
{


public:
	void receive(std::string message);
};
}

#endif
