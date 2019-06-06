#ifndef ACPROPULSION_H
#define ACPROPULSION_H

#include <memory>
#include <cstdint>
#include <Arduino.h>
#include <FastCRC.h>
#include "Vms.h"
#include "VehicleData.h"

namespace Vehicle
{
class AcPropulsion : public Vms
{

private:
	std::unique_ptr<HardwareSerial> serial;
	FastCRC16 crc16;
	int chargingCurrentLimit;
	int reverseChargingCurrentLimit;

	void sendCommand(unsigned char key[], unsigned char value[]);

	unsigned char* generateSignature(uint16_t dataLength);

public:
	AcPropulsion(std::unique_ptr<HardwareSerial> serial);

	AcPropulsion(const AcPropulsion &) = delete;

	AcPropulsion &operator=(const AcPropulsion &) = delete;

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
