#include "Messaging/Commands/ReverseChargeVehicle.h"

using namespace Messaging;

ReverseChargeVehicle::ReverseChargeVehicle(std::shared_ptr<Vehicle::VehicleClient> vehicle)
{
	this->vehicle = vehicle;
}

void ReverseChargeVehicle::execute()
{
	vehicle->startReverseCharging(this->current);
}

void ReverseChargeVehicle::parseParams(std::string params)
{
	float current;
	std::istringstream iss (params);
	iss >> current;
	this->current = current;
}
