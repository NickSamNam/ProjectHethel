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
		const char* DDDmm_mmmm = "DDDmm.mmmm"; //D degrees, m minutes.
		const char* DDmm_mmmm = "DDmm.mmmm"; //D degrees, m minutes.
		const char* cardinalDirection = "NSEW"; //North, South, East or West.
		const char* meters = "m";
		const char* timestamp = "hhmmss"; //h hours, m minutes, s seconds.
	} units;
};
}

#endif
