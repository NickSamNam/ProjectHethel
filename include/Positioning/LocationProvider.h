#ifndef LOCATIONPROVIDER_H
#define LOCATIONPROVIDER_H

#include <memory>
#include "Location.h"
#include "GPSClient.h"

namespace Positioning
{
class LocationProvider
{

private:
	std::unique_ptr<GPSClient> gps;
public:
	
	LocationProvider(std::unique_ptr<GPSClient> gps);

	LocationProvider(const LocationProvider &) = delete;

	LocationProvider &operator=(const LocationProvider &) = delete;
	
	Location getLocation();
	
};
}

#endif
