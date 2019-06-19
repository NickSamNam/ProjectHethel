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
		const char* DDDmm_mmmm = "DDDmm.mmmm"; //D degrees, m minutes.
		const char* DDmm_mmmm = "DDmm.mmmm"; //D degrees, m minutes.
		const char* cardinalDirection = "NSEW"; //North, South, East or West.
		const char* meters = "m";
	} units;

	static bool isValid(long value);
	static bool isValid(char value);
};
}
#endif
