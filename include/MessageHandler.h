#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <map>
#include <string>

class MessageHandler
{

protected:
	std::map<std::string, Command> commands;

public:
	virtual std::string generateMessage(VehicleData vehicleData, Location locationData) = 0;

	virtual Command parseMessage(std::string message) = 0;

	void addCommand(std::string name, Command command);
};

#endif
