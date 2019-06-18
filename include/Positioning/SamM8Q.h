#ifndef SAMM8Q_H
#define SAMM8Q_H

#include "GPSClient.h"
#include "Location.h"
#include <Arduino.h>

namespace Positioning
{
class SamM8Q : GPSClient
{

private:
	HardwareSerial *serial;
	String readData();
	static String getValue(String data, char separator, int index);
public:
	SamM8Q(HardwareSerial *serial);
	Location parseData(String line);
};
}

#endif
