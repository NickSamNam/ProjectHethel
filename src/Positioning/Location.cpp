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

bool Location::isValid()
{
	if(latitude > 0 && latitude < 9000 && longitude > 0 && longitude < 18000 && altitude > -500 && altitude < 6000)
	{
		return true;
	}
	return false;
}