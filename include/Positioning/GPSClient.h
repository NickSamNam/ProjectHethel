#ifndef GPSCLIENT_H
#define GPSCLIENT_H

#include "Location.h"
#include <WString.h>

namespace Positioning 
{
class GPSClient
{


public:
	virtual ~GPSClient(){};

	virtual String readData() = 0;

	virtual Location parseData(String line) = 0;
};
}

#endif
