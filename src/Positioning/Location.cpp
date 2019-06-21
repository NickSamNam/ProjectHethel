#include "Positioning/Location.h"

using namespace Positioning;

Location::Location()
    : longitude(0)
    , directionLong('\0')
    , latitude(0)
    , directionLat('\0')
    , altitude(0)
    , timestamp('\0')
    {}

bool Location::isValid(long value)
{
    return value != 0;
}

bool Location::isValid(char value)
{
    return value != '\0';
}

const char* Location::Units::DDDmm_mmmm_C = "DDDmm.mmmm_C";
const char* Location::Units::DDmm_mmmm_C = "DDmm.mmmm_C";
const char* Location::Units::meters = "m";