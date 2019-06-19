#include "Positioning/SamM8Q.h"

using namespace Positioning;

SamM8Q::SamM8Q(HardwareSerial *serial)
{
	this->serial = serial;
	serial->begin(9600);
}

String SamM8Q::readData()
{
	int iterations = 0;
	while (serial->available())
	{
		const String line = serial->readStringUntil('\n');
		if (line.startsWith("$GNGGA"))
		{
			return line;
		}
		else if (iterations == 100)
		{
			return "error"; // no line with $GNGGA found
		}
		iterations++;
	}
	return "error"; // serial not available
}

Location SamM8Q::parseData(String line)
{
	struct Location *loc = new Location();

	if (line != "error")
	{
		loc->longitude = getValue(line, ',', 4).toFloat();
		loc->directionLong = getValue(line, ',', 5).charAt(0);
		loc->latitude = getValue(line, ',', 2).toFloat();
		loc->directionLat = getValue(line, ',', 3).charAt(0);
		loc->altitude = getValue(line, ',', 9).toFloat();
		loc->timestamp = getValue(line, ',', 1).toFloat();
	}
	return *loc;
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