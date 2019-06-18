#include "../include/Networking/NetworkClient.h"

using namespace Networking;

SoftwareSerial s(16,17);

void NetworkClient::setup(){
	s.begin(9600);
}

void NetworkClient::sendJson(JsonObject json){

}

JsonObject NetworkClient::receiveJson(){

}

JsonObject NetworkClient::createJson(size_t capacity, char* json){
	DynamicJsonBuffer jsonBuffer(capacity);
	JsonObject& root = jsonBuffer.parseObject(json);
}

void NetworkClient::connectNetwork()
{
	// TODO - implement NetworkClient::connectNetwork
}

void NetworkClient::connectServer()
{
	// TODO - implement NetworkClient::connectServer
}

void NetworkClient::publishMessage(std::string topic, std::string message)
{
	/* Json looks like this
	{
		"command":{
			"name":"PUBLISHMESSAGE",
			"topic":topic,
			"message":message
		}
	}
	*/
	const size_t capacity = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(3);
	DynamicJsonBuffer jsonBuffer(capacity);
	JsonObject& root = jsonBuffer.createObject();
	JsonObject& command = root.createNestedObject("command");
	command["name"] = "PUBLISHMESSAGE";
	command["topic"] = topic.c_str();
	command["message"] = message.c_str();
	
	if(s.available()>0){
		root.printTo(s);
	}
}

void NetworkClient::subscribeTopic(std::string topic, MqttSubscribe callback)
{
	/* Json looks like this
	{
		"command":{
			"name":"SUBSCRIBETOPIC",
			"topic":topic
		}
	}
	*/
	const size_t capacity = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(2);
	DynamicJsonBuffer jsonBuffer(capacity);
	JsonObject& root = jsonBuffer.createObject();
	JsonObject& command = root.createNestedObject("command");
	command["name"] = "SUBSCRIBETOPIC";
	command["topic"] = topic.c_str();
	
	if(s.available()>0){
		root.printTo(s);
	}
}
