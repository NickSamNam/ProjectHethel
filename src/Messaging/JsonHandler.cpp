#include "Messaging/JsonHandler.h"
#include "Vehicle/VehicleData.h"
#include "Positioning/Location.h"

using namespace Messaging;

std::string JsonHandler::generateMessage(Vehicle::VehicleData vehicleData, Positioning::Location locationData)
{
	// TODO - Maakt een JSON message volgens de spec van de API guys.
}

std::shared_ptr<Command> JsonHandler::parseMessage(std::string message){
	// TODO - Parsed een command, roept parseParams aan.
// 	{
//   "command": "reverse charge",
//   "params": {
//     "current": integer min 1 tm 6 max
//   }
}
