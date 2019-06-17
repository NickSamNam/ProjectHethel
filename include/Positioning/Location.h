#ifndef LOCATION_H
#define LOCATION_H

#include <NeoTime.h>

namespace Positioning
{
struct Location
{

public:
	long longitude;
	char directionLong;
	long latitude;
	char directionLat;
	long altitude;
};
}

#endif
