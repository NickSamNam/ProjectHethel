#ifndef SAMM8Q_H
#define SAMM8Q_H

#include "GPSClient.h"
#include "Location.h"
#include <HardwareSerial.h>
#include <TinyGPS.h>
namespace Positioning
{
class SamM8Q : GPSClient
{


public:
	int readData();

	Location parseData(int gpsData);
};
}

#endif
