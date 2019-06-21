#ifndef CHARGEVEHICLE_H
#define CHARGEVEHICLE_H

#include "Command.h"
#include "Vehicle/VehicleClient.h"

namespace Messaging
{
class ChargeVehicle : public Command
{
private:
	std::shared_ptr<Vehicle::VehicleClient> vehicle;

	int current;

public:
	ChargeVehicle(std::shared_ptr<Vehicle::VehicleClient> vehicle);

	void execute();

	void parseParams(std::map<String, String> params);
};
}

#endif
