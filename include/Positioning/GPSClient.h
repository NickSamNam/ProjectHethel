#ifndef GPSCLIENT_H
#define GPSCLIENT_H

#include "Location.h"
#include <Arduino.h>

namespace Positioning 
{
class GPSClient
{


public:
	virtual String readData() = 0;

	virtual Location parseData(String line) = 0;
};
}

#endif
