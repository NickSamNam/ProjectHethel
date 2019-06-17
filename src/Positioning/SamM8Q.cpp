#include "Positioning/SamM8Q.h"

String line;
const int offset = 1; // Central European Time
gps_fix currentFix;

using namespace Positioning;

Location SamM8Q::readData()
{

	while (Serial1.available())
	{
		Serial1.readStringUntil("\n");
		Serial.println(line);
		if (line.startsWith("$GNGGA"))
		{
			return parseData();
		}
	}
}

Location SamM8Q::parseData()
{
	Serial.println("parsing");

	struct Location loc;

	loc.longitude = getValue(line, ',', 4).toFloat();
	loc.directionLong = getValue(line, ',', 5);
	loc.latitude = getValue(line, ',', 2).toFloat();
	loc.directionLat = getValue(line, ',', 3);
	loc.altitude = getValue(line, ',', 9).toFloat();

	return loc;
}

String SamM8Q::getValue(String data, char separator, int index)
{
	int found = 0;
	int strIndex[] = {0, -1};
	int maxIndex = data.length() - 1;

	for (int i = 0; i <= maxIndex && found <= index; i++)
	{
		if (data.charAt(i) == separator || i == maxIndex)
		{
			found++;
			strIndex[0] = strIndex[1] + 1;
			strIndex[1] = (i == maxIndex) ? i + 1 : i;
		}
	}

	return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}