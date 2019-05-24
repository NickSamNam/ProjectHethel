#ifndef ACPROPULSION_H
#define ACPROPULSION_H

#include <cstdint>
#include <Arduino.h>
#include <FastCRC.h>
#include "Vms.h"
#include "VehicleData.h"

namespace Vehicle
{
class AcPropulsion : Vms
{

private:
	HardwareSerial serial;
	FastCRC16 crc16;
	int chargingCurrentLimit;
	int reverseChargingCurrentLimit;

	void sendCommand(unsigned char key[], unsigned char value[]);

	unsigned char* generateSignature(uint16_t dataLength);

public:
	AcPropulsion(HardwareSerial serial);

	size_t readData(unsigned char *buffer, size_t length);

	VehicleData parseData(unsigned char data[]);

	bool startCharging(int current);

	bool startReverseCharging(int current);

	bool stopCharging();

	void imposeChargingCurrentLimit(int current);

	void imposeReverseChargingCurrentLimit(int current);
};
}

#endif
