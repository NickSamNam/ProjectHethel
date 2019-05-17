#ifndef STOPCHARGINGVEHICLE_H
#define STOPCHARGINGVEHICLE_H

#include "VehicleCommand.h"
#include "Vehicle/VehicleClient.h"

namespace Messaging
{
class StopChargingVehicle : VehicleCommand
{


public:
	StopChargingVehicle(VehicleClient vehicle);

	void execute();
};
}

#endif
