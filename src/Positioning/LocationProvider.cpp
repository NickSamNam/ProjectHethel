#include "Positioning/LocationProvider.h"

using namespace Positioning;

LocationProvider::LocationProvider(std::unique_ptr<GPSClient> gps) : gps(std::move(gps)) {}

Location LocationProvider::getLocation()
{
	
	return gps->parseData(gps->readData());
}

