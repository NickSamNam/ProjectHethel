#ifndef SAMM8Q_H
#define SAMM8Q_H

#include "GPSClient.h"
#include "Location.h"
#include <HardwareSerial.h>
#include <NMEAGPS.h>
#include <GPSport.h>

namespace Positioning
{
class SamM8Q : GPSClient
{


public:
	Location readData();
	String getValue(String data, char separator, int index);
	Location parseData();
};
}

#endif
