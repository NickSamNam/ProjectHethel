#include "Messaging/Commands/ChargeVehicle.h"

using namespace Messaging;

ChargeVehicle::	ChargeVehicle(std::shared_ptr<Vehicle::VehicleClient> vehicle)
{
	this->vehicle = vehicle;
}

void ChargeVehicle::execute()
{
	vehicle->startCharging(this->current);
}

void ChargeVehicle::parseParams(std::map<String, String> params)
{
	current = params["current"].toInt();
}
