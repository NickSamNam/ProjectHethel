#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <map>
#include <set>
#include "MqttSubscribe.h"

namespace Networking
{
class NetworkClient
{

private:
	std::map<std::string, std::set<MqttSubscribe>> subscriptions;

public:
	void connectNetwork();

	void connectServer();

	void publishMessage(std::string topic, std::string message);

	void subscribeTopic(std::string topic, MqttSubscribe callback);
};
}

#endif
