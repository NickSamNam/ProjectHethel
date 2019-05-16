#ifndef VEHICLECOMMAND_H
#define VEHICLECOMMAND_H

#include "VehicleCommand.h"
#include "VehicleClient.h"

class VehicleCommand : Command
{

public:
	VehicleClient vehicle;

	VehicleCommand(VehicleClient vehicle);

	virtual void execute() = 0;
};

#endif
