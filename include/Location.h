#ifndef LOCATION_H
#define LOCATION_H

#include <Time.h>

struct Location
{

public:
	long longitude;
	long latitude;
	long altitude;
	time_t timestamp;
};

#endif
