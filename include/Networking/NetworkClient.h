#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include "Networking/MqttSubscribe.h"
#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#include <map>
#include <set>

namespace Networking
{
class NetworkClient
{

private:

public:
	void setup();

	void sendJson(JsonObject json);

	JsonObject receiveJson();

	JsonObject createJson(size_t capacity, char* json);

	void connectNetwork();

	void connectServer();

	void publishMessage(std::string topic, std::string message);

	void subscribeTopic(std::string topic, MqttSubscribe callback);
};
}

#endif
