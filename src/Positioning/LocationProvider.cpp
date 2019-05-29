#include "Positioning/LocationProvider.h"

using namespace Positioning;

Location LocationProvider::getLocation()
{
	SamM8Q gps = new SamM8Q();
	return gps.parseData(gps.readData());
}
