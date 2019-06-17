#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include <ArduinoJson.h>
#include <string>
#include <memory>
#include "MessageHandler.h"
#include "Vehicle/VehicleData.h"
#include "Positioning/Location.h"
#include "./Commands/Command.h"
#include "./Commands/ChargeVehicle.h"
#include "./Commands/ReverseChargeVehicle.h"
#include "./Commands/StopChargingVehicle.h"

namespace Messaging
{
class JsonHandler : MessageHandler
{
public:
	std::string generateMessage(Vehicle::VehicleData vehicleData, Positioning::Location locationData);

	std::shared_ptr<Command> parseMessage(std::string message);
};
}

#endif
