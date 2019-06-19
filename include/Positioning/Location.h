#ifndef LOCATION_H
#define LOCATION_H

#include <Time.h>
#include <string>

namespace Positioning
{
struct Location
{
public:
	long longitude;
	long latitude;
	long altitude;
	time_t timestamp;

	static const struct Units {
		const char* coordinates = "DDDMM.MMMM";
	} units;
};
}

#endif
