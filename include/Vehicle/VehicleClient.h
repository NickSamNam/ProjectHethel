#ifndef VEHICLECLIENT_H
#define VEHICLECLIENT_H

#include <memory>
#include "VehicleData.h"
#include "Vms.h"

namespace Vehicle
{
class VehicleClient
{

private:
	std::unique_ptr<Vms> vms;

public:
	VehicleClient(std::unique_ptr<Vms> vms);

	VehicleData getData();

	void startCharging(int current);

	void startReverseCharging(int current);

	void stopCharging();
};
}

#endif
