#include "Positioning/SamM8Q.h"


unsigned char* buffer;
TinyGPS gps;
const int offset = 1;   // Central European Time

using namespace Positioning;

int SamM8Q::readData()
{
	Serial1.begin(9600);
	while(Serial1.available()){
		return Serial1.read();
	}
}

Location SamM8Q::parseData(int gpsData)
{
	unsigned long age;
    int Year;
    byte Month, Day, Hour, Minute, Second;
	struct Location loc;
	float flat, flon;

	if(gps.encode(gpsData))
	{
	gps.f_get_position(&flat, &flon);
	loc.longitude = flon;
	loc.latitude = flat;
	loc.altitude = gps.f_altitude();
	gps.crack_datetime(&Year, &Month, &Day, &Hour, &Minute, &Second, NULL, &age);
      if (age < 500) {
        // set the Time to the latest GPS reading
        setTime(Hour, Minute, Second, Day, Month, Year);
        adjustTime(offset * SECS_PER_HOUR);
		loc.timestamp = now();
      }
	}
	return loc;
}
