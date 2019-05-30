#include "Messaging/Commands/ReverseChargeVehicle.h"

using namespace Messaging;

ReverseChargeVehicle::ReverseChargeVehicle(std::shared_ptr<Vehicle::VehicleClient> vehicle)
{
	this->vehicle = vehicle;
}

void ReverseChargeVehicle::execute()
{
	// TODO - implement ReverseChargeVehicle::execute
	throw "Not yet implemented";
}

void ReverseChargeVehicle::parseParams(std::string params)
{
	// TODO - implement ReverseChargeVehicle::parseParams
	throw "Not yet implemented";
}
