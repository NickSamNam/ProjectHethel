#include "Messaging/Commands/ChargeVehicle.h"

using namespace Messaging;

ChargeVehicle::	ChargeVehicle(std::shared_ptr<Vehicle::VehicleClient> vehicle)
{
	this->vehicle = vehicle;
}

void ChargeVehicle::execute()
{
	// TODO - implement ChargeVehicle::execute
	throw "Not yet implemented";
}

void ChargeVehicle::parseParams(std::string params)
{
	// TODO - implement ChargeVehicle::parseParams
	throw "Not yet implemented";
}
