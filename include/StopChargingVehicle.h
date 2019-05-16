#ifndef STOPCHARGINGVEHICLE_H
#define STOPCHARGINGVEHICLE_H

#include "VehicleCommand.h"
#include "VehicleClient.h"

class StopChargingVehicle : VehicleCommand
{


public:
	StopChargingVehicle(VehicleClient vehicle);

	void execute();
};

#endif
