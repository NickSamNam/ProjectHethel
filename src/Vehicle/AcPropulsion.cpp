#include <stdexcept>
#include <limits>
#include "Vehicle/AcPropulsion.h"

using namespace Vehicle;

AcPropulsion::AcPropulsion(std::unique_ptr<HardwareSerial> serial)
	: serial(std::move(serial))
	, crc16(FastCRC16())
	, chargingCurrentLimit(std::numeric_limits<int>::max())
	, reverseChargingCurrentLimit((std::numeric_limits<int>::max()))
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

size_t AcPropulsion::readData(unsigned char *buffer, size_t bufferSize)
{
	// Read bytes until signature is found.
	unsigned char signature[2];
	do {
		if (serial->readBytes(signature, 2) != 2)
			return 0;
	} while ((signature[0] & 0b11111100) != 0xAC);

	// Get datalength from signature and subtract crc length.
	size_t length = (((signature[0] & 0b11) << 8) | signature[1]) - 2;

	// throw exception if buffer size is too small.
	if (bufferSize < length)
		return 0;

	// Read CRC.
	unsigned char crc_b[2];
	if (serial->readBytes(crc_b, 2) != 2)
		return 0;
	// CRC bytes to uint16.
	u_int16_t crc = ((crc_b[0] << 8) | crc_b[1]);

	// Read the remaining data into the buffer.
	if (serial->readBytes(buffer, length) != length)
		return 0;

	// Check the CRC checksum.
	if (crc16.ccitt(buffer, length) != crc)
		return 0;

	// Return the length of the data which was written to the buffer.
	return length;
}

VehicleData AcPropulsion::parseData(unsigned char data[])
{
	// TODO - implement AcPropulsion::parseData
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
