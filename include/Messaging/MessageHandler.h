#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <map>
#include <memory>
#include <string>
#include "./Commands/Command.h"
#include "Vehicle/VehicleData.h"
#include "Positioning/Location.h"

namespace Messaging
{
class MessageHandler
{
protected:
	std::map<std::string, std::shared_ptr<Command>> commands;

public:
	void addCommand(std::string name, std::shared_ptr<Command> command);

	virtual std::string generateMessage(Vehicle::VehicleData vehicleData, Positioning::Location locationData) = 0;

	virtual std::shared_ptr<Command> parseMessage(std::string message) = 0;
};
}

#endif
