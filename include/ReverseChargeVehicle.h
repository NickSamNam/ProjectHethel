#ifndef REVERSECHARGEVEHICLE_H
#define REVERSECHARGEVEHICLE_H

#include <string>
#include "VehicleCommand.h"
#include "JsonParams.h"
#include "VehicleClient.h"

class ReverseChargeVehicle : VehicleCommand, JsonParams
{

public:
	int current;

	ReverseChargeVehicle(VehicleClient vehicle);

	void execute();

	void parseParams(std::string params);
};

#endif
