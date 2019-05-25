#ifndef VEHICLECLIENT_H
#define VEHICLECLIENT_H

#include "VehicleData.h"

namespace Vehicle
{
class VehicleClient
{


public:
	VehicleData getData();

	void startCharging(int current);

	void startReverseCharging(int current);

	void stopCharging();
};
}

#endif