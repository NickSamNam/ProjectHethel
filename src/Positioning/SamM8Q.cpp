#include "Positioning/SamM8Q.h"

using namespace Positioning;

SamM8Q::SamM8Q(HardwareSerial *serial)
{
	this->serial = serial;
}

String SamM8Q::readData()
{
	while (serial->available())
	{
		const String line = serial->readStringUntil('\n');
		if (line.startsWith("$GNGGA"))
		{
			return line;
		}
	}
}

Location SamM8Q::parseData(String line)
{
	struct Location loc;

	loc.longitude = getValue(line, ',', 4).toFloat();
	loc.directionLong = getValue(line, ',', 5).charAt(0);
	loc.latitude = getValue(line, ',', 2).toFloat();
	loc.directionLat = getValue(line, ',', 3).charAt(0);
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