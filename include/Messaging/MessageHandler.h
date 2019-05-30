#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <map>
#include <string>
#include "Commands/Command.h"
#include "Vehicle/VehicleData.h"
#include "Positioning/Location.h"

namespace Messaging
{
class MessageHandler
{

protected:
	std::map<std::string, Command> commands;

public:
	virtual std::string generateMessage(Vehicle::VehicleData vehicleData, Positioning::Location locationData) = 0;

	virtual Command parseMessage(std::string message) = 0;

	void addCommand(std::string name, Command command);
};
}

#endif
