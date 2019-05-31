#ifndef ACPROPULSION_H
#define ACPROPULSION_H

#include <memory>
#include <cstdint>
#include <Arduino.h>
#include <FastCRC.h>
#include "Vms.h"
#include "VehicleData.h"
#include "logger3_public.h"

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
	typedef union
	{
		l3frame_bms_summary_t bmsSummary;
		l3frame_sys_highrate_t sysHighRate;
		l3frame_sys_lowrate_t sysLowRate;
		l3frame_triplog_t tripLog;
	} l3frame_t;

	AcPropulsion(std::unique_ptr<HardwareSerial> serial);

	AcPropulsion(const AcPropulsion &) = delete;

	AcPropulsion &operator=(const AcPropulsion &) = delete;

	int readHeader(l3_header_t *header);

	int readFrame(l3_header_t header, l3frame_t *frame);

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
