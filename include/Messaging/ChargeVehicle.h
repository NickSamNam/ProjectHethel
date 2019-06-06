#ifndef CHARGEVEHICLE_H
#define CHARGEVEHICLE_H

#include <string>
#include "VehicleCommand.h"
#include "JsonParams.h"
#include "Vehicle/VehicleClient.h"

namespace Messaging
{
class ChargeVehicle : VehicleCommand, JsonParams
{

public:
	int current;

	ChargeVehicle(VehicleClient vehicle);

	void execute();

	void parseParams(std::string params);
};
}

#endif
