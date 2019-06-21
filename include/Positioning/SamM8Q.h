#ifndef SAMM8Q_H
#define SAMM8Q_H

#include "GPSClient.h"
#include "Location.h"
#include <Arduino.h>

namespace Positioning
{
class SamM8Q : public GPSClient
{

private:
	HardwareSerial *serial;
	
	static String getValue(String data, char separator, int index);
public:
	String readData();
	SamM8Q(HardwareSerial *serial);
	Location parseData(String line);
};
}

#endif
