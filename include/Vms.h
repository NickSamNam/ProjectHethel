#ifndef VMS_H
#define VMS_H

#include "VehicleData.h"

class Vms
{


public:
	unsigned char* readData();

	VehicleData parseData(unsigned char data[]);

	bool startCharging(int current);

	bool startReverseCharging(int current);

	bool stopCharging();

	void imposeChargingCurrentLimit(int current);

	void imposeReverseChargingCurrentLimit(int current);
};

#endif
