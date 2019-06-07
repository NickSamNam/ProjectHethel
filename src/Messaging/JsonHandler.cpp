#include "Messaging/JsonHandler.h"
#include "Vehicle/VehicleData.h"
#include "Positioning/Location.h"

using namespace Messaging;

std::string JsonHandler::generateMessage(Vehicle::VehicleData vehicleData, Positioning::Location locationData)
{
	// TODO - implement JsonHandler::generateMessage
	throw "Not yet implemented";
}

std::shared_ptr<Command> JsonHandler::parseMessage(std::string message){
	// TODO - implement JsonHandler::parseMessage
	throw "Not yet implemented";
}
