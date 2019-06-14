#include <limits>
#include "Vehicle/AcPropulsion.h"

using namespace Vehicle;

AcPropulsion::AcPropulsion(HardwareSerial *serial) : AcPropulsion(serial, std::numeric_limits<uint8_t>::max(), std::numeric_limits<uint8_t>::max()) {}

AcPropulsion::AcPropulsion(HardwareSerial *serial, uint8_t maxChargingCurrent, uint8_t maxReverseChargingCurrent) 
	: serial(serial)
	, crc16(FastCRC16())
	, chargingCurrentLimit(maxChargingCurrent)
	, reverseChargingCurrentLimit(maxReverseChargingCurrent)
	, dataAccum()
	, accumFlag(0)
	, accumMask((1 << L3PAYLOAD_ID_BMS_SUMMARY) | (1 << L3FRAME_ID_SYS_HIRATE) | (1 << L3FRAME_ID_SYS_LOWRATE) | (1 << L3PAYLOAD_ID_TRIPLOG))
	, maxTries(5)
{
	// 57600 baudrate, 8 data bits, no parity, 1 stop bit
	this->serial->begin(57600, SERIAL_8N1);
}

void AcPropulsion::sendCommand(unsigned char key[], unsigned char value[])
{
	// TODO - implement AcPropulsion::sendCommand
}

unsigned char *AcPropulsion::generateSignature(uint16_t dataLength)
{
	// TODO - implement AcPropulsion::generateSignature
}

int AcPropulsion::readHeader(l3_header_t *header)
{
	int nTries = 0;
	// Read bytes until signature is found.
	unsigned char signature[2];
	do {
		if (nTries++ >= maxTries || serial->readBytes(signature, 2) != 2)
			return 1;
		header->signature.u16 = (signature[0] << 8) | signature[1];
	} while (header->signature.bits.signature != L3_SIGNATURE_VALUE);

	// Read CRC.
	unsigned char crc[2];
	if (serial->readBytes(crc, 2) != 2)
		return 2;
	header->crc = ((crc[0] << 8) | crc[1]);

	// Read Payload ID.
	header->id_and_timestamp.payload_id = serial->read();
	if (header->id_and_timestamp.payload_id < 0)
		return 3;
	
	// Read timestamp.
	unsigned char timestamp[3];
	if (serial->readBytes(timestamp, 3) != 3)
		return 4;
	header->id_and_timestamp.payload_timestamp = ((timestamp[0] << 16) | (timestamp[1] << 8) | (timestamp[2]));

	return 0;
}

int AcPropulsion::readFrame(l3_header_t header, l3frame_t *frame)
{
	size_t frameLength = header.signature.bits.remaining_bytes - 6;
	unsigned char buffer[frameLength];
	// Read the remaining data into the buffer.
	if (serial->readBytes(buffer, frameLength) != frameLength)
		return 1;

	// Check the CRC checksum.
	if (crc16.ccitt(buffer, frameLength) != header.crc)
		return 2;

	switch (header.id_and_timestamp.payload_id)
	{
	case L3PAYLOAD_ID_BMS_SUMMARY:
		if (frameLength < 13)
			return 3;
		frame->bmsSummary.header 				= header;
		frame->bmsSummary.v_min 				= ((buffer[0] << 8) | buffer[1]);
		frame->bmsSummary.v_max 				= ((buffer[2] << 8) | buffer[3]);
		frame->bmsSummary.v_avg 				= ((buffer[4] << 8) | buffer[5]);
		frame->bmsSummary.t_min 				= ((buffer[6] << 8) | buffer[7]);
		frame->bmsSummary.t_max 				= ((buffer[8] << 8) | buffer[9]);
		frame->bmsSummary.t_avg 				= ((buffer[10] << 8) | buffer[11]);
		frame->bmsSummary.soc_percent 			= buffer[12];
		break;
	case L3FRAME_ID_SYS_HIRATE:
		if (frameLength < 16)
			return 3;
		frame->sysHighRate.header 				= header;
		frame->sysHighRate.error_bitmap 		= ((((buffer[0] << 8) | buffer[1]) << 16) | ((buffer[2] << 8) | buffer[3]));
		frame->sysHighRate.v_bat_x10 			= ((buffer[4] << 8) | buffer[5]);
		frame->sysHighRate.i_sys_x10 			= ((buffer[6] << 8) | buffer[7]);
		frame->sysHighRate.i_hyb_x10 			= ((buffer[8] << 8) | buffer[9]);
		frame->sysHighRate.i_aux_x10 			= ((buffer[10] << 8) | buffer[11]);
		frame->sysHighRate.motor_rpm 			= ((buffer[12] << 8) | buffer[13]);
		frame->sysHighRate.ui_state_index 		= buffer[14];
		frame->sysHighRate.charge_result 		= buffer[15];
		break;
	case L3FRAME_ID_SYS_LOWRATE:
		if (frameLength < 17)
			return 3;
		frame->sysLowRate.header 				= header;
		frame->sysLowRate.motor_temp_x10 		= ((buffer[0] << 8) | buffer[1]);
		frame->sysLowRate.peu_temp_x10 			= ((buffer[2] << 8) | buffer[3]);
		frame->sysLowRate.batt_inlet_temp_x10 	= ((buffer[4] << 8) | buffer[5]);
		frame->sysLowRate.ambient_temp_x10 		= ((buffer[6] << 8) | buffer[7]);
		frame->sysLowRate.i_line_x10 			= ((buffer[8] << 8) | buffer[9]);
		frame->sysLowRate.v_line_x10 			= ((buffer[10] << 8) | buffer[11]);
		frame->sysLowRate.v_aps_x100 			= ((buffer[12] << 8) | buffer[13]);
		frame->sysLowRate.line_ampacity 		= buffer[14];
		frame->sysLowRate.bms_error[0] 			= buffer[15];
		frame->sysLowRate.bms_error[1] 			= buffer[16];
		break;
	case L3PAYLOAD_ID_BMS_VOLTAGE:
		return 3;
	case L3PAYLOAD_ID_BMS_TEMPERATURE:
		return 3;
	case L3PAYLOAD_ID_TRIPLOG:
		if (frameLength < 52)
			return 3;
		frame->tripLog.header 					= header;
		frame->tripLog.ah_drive_x10k 			= ((((buffer[0] << 8) | buffer[1]) << 16) | ((buffer[2] << 8) | buffer[3]));
		frame->tripLog.ah_regen_x10k 			= ((((buffer[4] << 8) | buffer[5]) << 16) | ((buffer[6] << 8) | buffer[7]));
		frame->tripLog.ah_charge_x10k 			= ((((buffer[8] << 8) | buffer[9]) << 16) | ((buffer[10] << 8) | buffer[11]));
		frame->tripLog.ah_dischg_x10k 			= ((((buffer[12] << 8) | buffer[13]) << 16) | ((buffer[14] << 8) | buffer[15]));
		frame->tripLog.wh_drive_x10 			= ((((buffer[16] << 8) | buffer[17]) << 16) | ((buffer[18] << 8) | buffer[19]));
		frame->tripLog.wh_regen_x10 			= ((((buffer[20] << 8) | buffer[21]) << 16) | ((buffer[22] << 8) | buffer[23]));
		frame->tripLog.wh_charge_x10 			= ((((buffer[24] << 8) | buffer[25]) << 16) | ((buffer[26] << 8) | buffer[27]));
		frame->tripLog.wh_dischg_x10 			= ((((buffer[28] << 8) | buffer[29]) << 16) | ((buffer[30] << 8) | buffer[31]));
		frame->tripLog.distance_cm 				= ((((buffer[32] << 8) | buffer[33]) << 16) | ((buffer[34] << 8) | buffer[35]));
		frame->tripLog.ac_wh_in 				= ((((buffer[36] << 8) | buffer[37]) << 16) | ((buffer[38] << 8) | buffer[39]));
		frame->tripLog.ac_wh_out 				= ((((buffer[40] << 8) | buffer[41]) << 16) | ((buffer[42] << 8) | buffer[43]));
		frame->tripLog.line_time_sec 			= ((((buffer[44] << 8) | buffer[45]) << 16) | ((buffer[46] << 8) | buffer[47]));
		frame->tripLog.drive_time_sec 			= ((((buffer[48] << 8) | buffer[49]) << 16) | ((buffer[50] << 8) | buffer[51]));
		break;
	default:
		return 4;
	}

	return 0;
}

int AcPropulsion::getData(VehicleData *data)
{
	int returnCode = -1;
	l3_header_t header;
	l3frame_t frame;
	while ((accumFlag & accumMask) != accumMask)
	{
		if (readHeader(&header))
		{
			returnCode = 1;
			break;
		}
		dataAccum.timestamp = header.id_and_timestamp.payload_timestamp;
		if (readFrame(header, &frame))
		{
			returnCode = 2;
			break;
		}

		switch (header.id_and_timestamp.payload_id)
		{
		case L3PAYLOAD_ID_BMS_SUMMARY:
			dataAccum.v_min = frame.bmsSummary.v_min / 1000;
			dataAccum.v_max = frame.bmsSummary.v_max / 1000;
			dataAccum.v_avg = frame.bmsSummary.v_avg / 1000;
			dataAccum.t_min = frame.bmsSummary.t_min / 10;
			dataAccum.t_max = frame.bmsSummary.t_max / 10;
			dataAccum.t_avg = frame.bmsSummary.t_avg / 10;
			dataAccum.soc = frame.bmsSummary.soc_percent;
			accumFlag |= (1 << L3PAYLOAD_ID_BMS_SUMMARY);
			break;
		case L3FRAME_ID_SYS_HIRATE:
			dataAccum.v_setpoint = frame.sysHighRate.v_bat_x10 / 1000; // probably not
			dataAccum.i_batt = frame.sysHighRate.i_sys_x10 / 10; // probably
			dataAccum.i_motor = frame.sysHighRate.i_hyb_x10 / 10; // probably
			dataAccum.i_acc = frame.sysHighRate.i_aux_x10 / 10; // probably
			dataAccum.motor = frame.sysHighRate.motor_rpm;
			accumFlag |= (1 << L3FRAME_ID_SYS_HIRATE);
			break;
		case L3FRAME_ID_SYS_LOWRATE:
			dataAccum.t_motor = frame.sysLowRate.motor_temp_x10 / 10;
			dataAccum.t_peu = frame.sysLowRate.motor_temp_x10 / 10;
			dataAccum.i_line1 = frame.sysLowRate.i_line_x10 / 10; // probably
			dataAccum.i_line2 = 0; // probably
			dataAccum.i_line3 = 0; // probably
			dataAccum.v_line1 = frame.sysLowRate.v_line_x10 / 10; // probably
			dataAccum.v_line2 = 0; // probably
			dataAccum.v_line3 = 0; // probably
			dataAccum.p_line = frame.sysLowRate.i_line_x10 * frame.sysLowRate.v_line_x10 / 100; // probably
			dataAccum.v_aps = frame.sysLowRate.v_aps_x100 / 100;
			dataAccum.i_setpoint = frame.sysLowRate.line_ampacity; // probably
			dataAccum.error = frame.sysLowRate.bms_error[1]; // maybe
			accumFlag |= (1 << L3FRAME_ID_SYS_LOWRATE);
			break;
		case L3PAYLOAD_ID_BMS_VOLTAGE:
			break;
		case L3PAYLOAD_ID_BMS_TEMPERATURE:
			break;
		case L3PAYLOAD_ID_TRIPLOG:
			accumFlag |= (1 << L3PAYLOAD_ID_TRIPLOG);
			break;
		default:
			break;
		}
		returnCode = 0;
	}

	*data = dataAccum;
	dataAccum = VehicleData();
	accumFlag = 0;
	return returnCode;
}

bool AcPropulsion::startCharging(int current)
{
	// TODO - implement AcPropulsion::startCharging
}

bool AcPropulsion::startReverseCharging(int current)
{
	// TODO - implement AcPropulsion::startReverseCharging
}

bool AcPropulsion::stopCharging()
{
	// TODO - implement AcPropulsion::stopCharging
}

void AcPropulsion::imposeChargingCurrentLimit(int current)
{
	// TODO - implement AcPropulsion::imposeChargingCurrentLimit
}

void AcPropulsion::imposeReverseChargingCurrentLimit(int current)
{
	// TODO - implement AcPropulsion::imposeReverseChargingCurrentLimit
}
