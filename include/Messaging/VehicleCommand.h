#ifndef VEHICLECOMMAND_H
#define VEHICLECOMMAND_H

#include "Command.h"
#include "Vehicle/VehicleClient.h"

using namespace Vehicle;

namespace Messaging
{
class VehicleCommand : Command
{

public:
	VehicleClient vehicle;

	VehicleCommand(VehicleClient vehicle);

	virtual void execute() = 0;
};
}

#endif
