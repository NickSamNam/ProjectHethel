#ifndef CHARGEVEHICLE_H
#define CHARGEVEHICLE_H

#include <string>
#include "../JsonParams.h"
#include "Command.h"
#include "Vehicle/VehicleClient.h"

namespace Messaging
{
class ChargeVehicle : Command, JsonParams
{
private:
	std::shared_ptr<Vehicle::VehicleClient> vehicle;

	int current;

public:
	ChargeVehicle(std::shared_ptr<Vehicle::VehicleClient> vehicle);

	void execute();

	void parseParams(std::string params);
};
}

#endif
