#ifndef SAMM8Q_H
#define SAMM8Q_H

#include "GPSClient.h"
#include "Location.h"

class SamM8Q : GPSClient
{


public:
	unsigned char* readData();

	Location parseData(unsigned char gpsData[]);
};

#endif
