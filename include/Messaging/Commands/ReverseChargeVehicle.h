#ifndef REVERSECHARGEVEHICLE_H
#define REVERSECHARGEVEHICLE_H

#include "Command.h"
#include "Vehicle/VehicleClient.h"

namespace Messaging
{
class ReverseChargeVehicle : public Command
{
private:	
	std::shared_ptr<Vehicle::VehicleClient> vehicle;

	int current;

public:
	ReverseChargeVehicle(std::shared_ptr<Vehicle::VehicleClient> vehicle);

	void execute();

	void parseParams(std::map<String, String> params);
};
}

#endif
