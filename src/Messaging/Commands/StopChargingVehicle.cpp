#include "Messaging/Commands/StopChargingVehicle.h"

using namespace Messaging;

StopChargingVehicle::StopChargingVehicle(std::shared_ptr<Vehicle::VehicleClient> vehicle)
{
	this->vehicle = vehicle;
}

void StopChargingVehicle::execute()
{
	// TODO - implement StopChargingVehicle::execute
	throw "Not yet implemented";
}
