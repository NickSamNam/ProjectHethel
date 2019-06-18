#ifndef LOCATION_H
#define LOCATION_H

namespace Positioning
{
struct Location
{

public:
	Location();
	long longitude; // DDDmm.mmmm degrees and minutes
	char directionLong; // W or E
	long latitude; // DDmm.mmmm degrees and minutes
	char directionLat; // N or S
	long altitude; // in meters
	long timestamp; // format hhmmss

	static bool isValid(Location loc);
};
}
#endif
