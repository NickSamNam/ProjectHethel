#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include <String.h>
#include <memory>

#include "MessageHandler.h"
#include "Vehicle/VehicleData.h"
#include "Positioning/Location.h"
#include "./Commands/Command.h"

namespace Messaging
{
class JsonHandler : public MessageHandler
{
public:
	String generateMessage(Vehicle::VehicleData vehicleData, Positioning::Location locationData);

	std::shared_ptr<Command> parseMessage(String message);
};
}

#endif
