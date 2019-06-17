#include "Positioning/LocationProvider.h"

using namespace Positioning;

LocationProvider::LocationProvider(){
	gps = new SamM8Q();
}

Location LocationProvider::getLocation()
{
	
	return gps->readData();
}

bool LocationProvider::isValid(Location loc)
{
	if(loc.latitude >= 0 && loc.latitude <= 9000)
	{
		if(loc.longitude >= 0 && loc.longitude <= 18000)
		{
			return true;
		}
	}
	return false;
}