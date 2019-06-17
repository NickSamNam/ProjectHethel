#ifndef VMS_H
#define VMS_H

#include "VehicleData.h"

namespace Vehicle
{
class Vms
{


public:
	virtual ~Vms(){};

	virtual int getData(VehicleData *data) = 0;

	virtual bool startCharging(unsigned int current) = 0;

	virtual bool startReverseCharging(unsigned int current) = 0;

	virtual bool stopCharging() = 0;

	virtual void imposeChargingCurrentLimit(unsigned int current) = 0;

	virtual void imposeReverseChargingCurrentLimit(unsigned int current) = 0;
};
}

#endif
