#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <map>
#include <memory>
#include "./Commands/Command.h"
#include "Vehicle/VehicleData.h"
#include "Positioning/Location.h"

namespace Messaging
{
class MessageHandler
{
protected:
	std::map<String, std::shared_ptr<Command>> commands;

public:
	void addCommand(String name, std::shared_ptr<Command> command);

	virtual String generateMessage(Vehicle::VehicleData vehicleData, Positioning::Location locationData) = 0;

	virtual std::shared_ptr<Command> parseMessage(String message) = 0;
};
}

#endif
