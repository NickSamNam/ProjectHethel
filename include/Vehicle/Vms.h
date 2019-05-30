#ifndef VMS_H
#define VMS_H

#include "VehicleData.h"

namespace Vehicle
{
class Vms
{


public:
	virtual ~Vms();

	virtual size_t readData(unsigned char *buffer, size_t length) = 0;

	virtual VehicleData parseData(unsigned char data[]) = 0;

	virtual bool startCharging(int current) = 0;

	virtual bool startReverseCharging(int current) = 0;

	virtual bool stopCharging() = 0;

	virtual void imposeChargingCurrentLimit(int current) = 0;

	virtual void imposeReverseChargingCurrentLimit(int current) = 0;
};
}

#endif
