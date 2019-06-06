#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include <string>
#include "MessageHandler.h"
#include "Vehicle/VehicleData.h"
#include "Positioning/Location.h"
#include "Command.h"

namespace Messaging
{
class JsonHandler : MessageHandler
{


public:
	std::string generateMessage(Vehicle::VehicleData vehicleData, Positioning::Location locationData);

	Command parseMessage(std::string message);
};
}

#endif
