#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include <string>
#include "MessageHandler.h"
#include "VehicleData.h"
#include "Location.h"
#include "Command.h"

class JsonHandler : MessageHandler
{


public:
	std::string generateMessage(VehicleData vehicleData, Location locationData);

	Command parseMessage(std::string message);
};

#endif
