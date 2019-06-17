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

	VehicleClient(const VehicleClient &) = delete;

	VehicleClient &operator=(const VehicleClient &) = delete;

	VehicleData getData();

	void startCharging(unsigned int current);

	void startReverseCharging(unsigned int current);

	void stopCharging();
};
}

#endif
