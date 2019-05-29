#ifndef LOCATIONPROVIDER_H
#define LOCATIONPROVIDER_H

#include "Location.h"
#include "SamM8Q.h"

namespace Positioning
{
class LocationProvider
{


public:
	Location getLocation();
};
}

#endif
