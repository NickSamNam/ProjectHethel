#include "Positioning/Location.h"

using namespace Positioning;

Location::Location()
    : longitude(0)
    , directionLong('W')
    , latitude(0)
    , directionLat('N')
    , altitude(0)
	, timestamp(0)

    {}

    bool Location::isValid(Location loc)
{
	if(loc.latitude > 0 && loc.latitude < 9000 && loc.longitude > 0 && loc.longitude < 18000 && loc.altitude > -500 && loc.altitude < 6000)
	{
		return true;
	}
	return false;
}