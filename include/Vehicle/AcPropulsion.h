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
	VehicleData dataAccum;
	int accumFlag;
	const int accumMask = ((1 << L3PAYLOAD_ID_BMS_SUMMARY) | (1 << L3FRAME_ID_SYS_HIRATE) | (1 << L3FRAME_ID_SYS_LOWRATE) | (1 << L3PAYLOAD_ID_TRIPLOG));

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

	int getData(VehicleData *data);

	bool startCharging(int current);

	bool startReverseCharging(int current);

	bool stopCharging();

	void imposeChargingCurrentLimit(int current);

	void imposeReverseChargingCurrentLimit(int current);
};
}

#endif
