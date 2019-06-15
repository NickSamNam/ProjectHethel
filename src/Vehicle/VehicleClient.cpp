#include "Vehicle/VehicleClient.h"

using namespace Vehicle;

VehicleClient::VehicleClient(std::unique_ptr<Vms> vms) : vms(std::move(vms)) {}

VehicleData VehicleClient::getData()
{
	VehicleData data;
	vms->getData(&data);
	return data;
}

void VehicleClient::startCharging(unsigned int current)
{
	vms->startCharging(current);
}

void VehicleClient::startReverseCharging(unsigned int current)
{
	vms->startReverseCharging(current);
}

void VehicleClient::stopCharging()
{
	vms->stopCharging();
}
