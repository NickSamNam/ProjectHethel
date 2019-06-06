#ifndef REVERSECHARGEVEHICLE_H
#define REVERSECHARGEVEHICLE_H

#include <string>
#include "VehicleCommand.h"
#include "JsonParams.h"
#include "Vehicle/VehicleClient.h"

namespace Messaging
{
class ReverseChargeVehicle : VehicleCommand, JsonParams
{

public:
	int current;

	ReverseChargeVehicle(VehicleClient vehicle);

	void execute();

	void parseParams(std::string params);
};
}

#endif
