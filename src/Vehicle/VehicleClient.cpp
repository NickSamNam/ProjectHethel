#include "Vehicle/VehicleClient.h"

using namespace Vehicle;

VehicleClient::VehicleClient(std::unique_ptr<Vms> vms) : vms(std::move(vms)) {}

VehicleData VehicleClient::getData()
{
	VehicleData data;
	vms->getData(&data);
	return data;
}

void VehicleClient::startCharging(int current)
{
	// TODO - implement VehicleClient::startCharging
}

void VehicleClient::startReverseCharging(int current)
{
	// TODO - implement VehicleClient::startReverseCharging
}

void VehicleClient::stopCharging()
{
	// TODO - implement VehicleClient::stopCharging
}
