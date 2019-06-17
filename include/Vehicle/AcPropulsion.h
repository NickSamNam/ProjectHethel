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
	HardwareSerial *serial;
	FastCRC16 crc16;
	uint8_t chargingCurrentLimit;
	uint8_t reverseChargingCurrentLimit;
	VehicleData dataAccum;
	uint8_t accumFlag;
	const int maxTries;

	typedef union
	{
		l3frame_bms_summary_t bmsSummary;
		l3frame_sys_highrate_t sysHighRate;
		l3frame_sys_lowrate_t sysLowRate;
		l3frame_triplog_t tripLog;
	} l3frame_t;

	int readHeader(l3_header_t *header);

	int readFrame(l3_header_t header, l3frame_t *frame);

	int sendCommand(uint8_t id, unsigned char* arguments = nullptr, size_t length = 0);

	void setReverseChargingCommand(unsigned int current);

public:

	AcPropulsion(HardwareSerial *serial);

	AcPropulsion(HardwareSerial *serial, uint8_t maxChargingCurrent, uint8_t maxReverseChargingCurrent);

	AcPropulsion(const AcPropulsion &) = delete;

	AcPropulsion &operator=(const AcPropulsion &) = delete;

	int getData(VehicleData *data);

	bool startCharging(unsigned int current);

	bool startReverseCharging(unsigned int current);

	bool stopCharging();

	void imposeChargingCurrentLimit(unsigned int current);

	void imposeReverseChargingCurrentLimit(unsigned int current);
};
}

#endif
