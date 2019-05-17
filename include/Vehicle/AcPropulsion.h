#ifndef ACPROPULSION_H
#define ACPROPULSION_H

#include <cstdint>
#include "Vms.h"
#include "VehicleData.h"

namespace Vehicle
{
class AcPropulsion : Vms
{

private:
	int chargingCurrentLimit;
	int reverseChargingCurrentLimit;

	void sendCommand(unsigned char key[], unsigned char value[]);

	unsigned char* generateSignature(uint16_t dataLength);

	unsigned char* generateCRC(unsigned char data[]);

public:
	unsigned char* readData();

	VehicleData parseData(unsigned char data[]);

	bool startCharging(int current);

	bool startReverseCharging(int current);

	bool stopCharging();

	void imposeChargingCurrentLimit(int current);

	void imposeReverseChargingCurrentLimit(int current);
};
}

#endif
