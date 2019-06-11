#ifndef REVERSECHARGEVEHICLE_H
#define REVERSECHARGEVEHICLE_H

#include <string>
#include "../JsonParams.h"
#include "Command.h"
#include "Vehicle/VehicleClient.h"

namespace Messaging
{
class ReverseChargeVehicle : Command, JsonParams
{
private:	
	std::shared_ptr<Vehicle::VehicleClient> vehicle;

	int current;

public:
	ReverseChargeVehicle(std::shared_ptr<Vehicle::VehicleClient> vehicle);

	void execute();

	void parseParams(std::string params);
};
}

#endif
