#ifndef REVERSECHARGEVEHICLE_H
#define REVERSECHARGEVEHICLE_H

#include <string>
#include "Command.h"
#include "Vehicle/VehicleClient.h"

namespace Messaging
{
class ReverseChargeVehicle : Command
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
