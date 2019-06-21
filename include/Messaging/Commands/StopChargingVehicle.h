#ifndef STOPCHARGINGVEHICLE_H
#define STOPCHARGINGVEHICLE_H

#include "Command.h"
#include "Vehicle/VehicleClient.h"

namespace Messaging
{
class StopChargingVehicle : public Command
{
private:
	std::shared_ptr<Vehicle::VehicleClient> vehicle;

public:
	StopChargingVehicle(std::shared_ptr<Vehicle::VehicleClient> vehicle);

	void execute();

	void parseParams(std::map<String, String> params);
};
}

#endif
