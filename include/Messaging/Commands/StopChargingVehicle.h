#ifndef STOPCHARGINGVEHICLE_H
#define STOPCHARGINGVEHICLE_H

#include <string>
#include "Command.h"
#include "Vehicle/VehicleClient.h"

namespace Messaging
{
class StopChargingVehicle : Command
{
private:
	std::shared_ptr<Vehicle::VehicleClient> vehicle;

public:
	StopChargingVehicle(std::shared_ptr<Vehicle::VehicleClient> vehicle);

	void execute();

	void parseParams(std::string params);
};
}

#endif
