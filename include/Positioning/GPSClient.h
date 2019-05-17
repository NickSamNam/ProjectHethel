#ifndef GPSCLIENT_H
#define GPSCLIENT_H

#include "Location.h"

namespace Positioning 
{
class GPSClient
{


public:
	unsigned char* readData();

	Location parseData(unsigned char gpsData[]);
};
}

#endif
