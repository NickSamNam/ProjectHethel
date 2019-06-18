#ifndef LOCATIONPROVIDER_H
#define LOCATIONPROVIDER_H

#include <memory>
#include "Location.h"
#include "SamM8Q.h"

namespace Positioning
{
class LocationProvider
{

private:
	std::unique_ptr<GPSClient> gps;
public:
	
	LocationProvider(std::unique_ptr<GPSClient> gps);
	Location getLocation();
	
};
}

#endif
