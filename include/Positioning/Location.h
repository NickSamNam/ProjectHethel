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

	static const struct Units {
		static const char* DDDmm_mmmm_C; //D degrees, m minutes, C for cardinal direction N or S.
		static const char* DDmm_mmmm_C; //D degrees, m minutes, C for cardinal direction E or W.
		static const char* meters;
	} units;

	static bool isValid(long value);
	static bool isValid(char value);
};
}
#endif
