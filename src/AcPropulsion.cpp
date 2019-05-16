#include "AcPropulsion.h"

void AcPropulsion::sendCommand(unsigned char key[], unsigned char value[])
{
	// TODO - implement AcPropulsion::sendCommand
	throw "Not yet implemented";
}

unsigned char* AcPropulsion::generateSignature(uint16_t dataLength)
{
	// TODO - implement AcPropulsion::generateSignature
	throw "Not yet implemented";
}

unsigned char* AcPropulsion::generateCRC(unsigned char data[])
{
	// TODO - implement AcPropulsion::generateCRC
	throw "Not yet implemented";
}

unsigned char* AcPropulsion::readData()
{
	// TODO - implement AcPropulsion::readData
	throw "Not yet implemented";
}

VehicleData AcPropulsion::parseData(unsigned char data[])
{
	// TODO - implement AcPropulsion::parseData
	throw "Not yet implemented";
}

bool AcPropulsion::startCharging(int current)
{
	// TODO - implement AcPropulsion::startCharging
	throw "Not yet implemented";
}

bool AcPropulsion::startReverseCharging(int current)
{
	// TODO - implement AcPropulsion::startReverseCharging
	throw "Not yet implemented";
}

bool AcPropulsion::stopCharging()
{
	// TODO - implement AcPropulsion::stopCharging
	throw "Not yet implemented";
}

void AcPropulsion::imposeChargingCurrentLimit(int current)
{
	// TODO - implement AcPropulsion::imposeChargingCurrentLimit
	throw "Not yet implemented";
}

void AcPropulsion::imposeReverseChargingCurrentLimit(int current)
{
	// TODO - implement AcPropulsion::imposeReverseChargingCurrentLimit
	throw "Not yet implemented";
}
