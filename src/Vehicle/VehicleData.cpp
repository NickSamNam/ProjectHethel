#include <limits>
#include <cmath>
#include "Vehicle/VehicleData.h"

using namespace Vehicle;

VehicleData::VehicleData()
    : timestamp(std::numeric_limits<uint32_t>::max())
    , v_min(NAN)
    , v_max(NAN)
    , v_avg(NAN)
    , i_batt(NAN)
    , i_motor(NAN)
    , i_acc(NAN)
    , t_min(NAN)
    , t_max(NAN)
    , t_avg(NAN)
    , t_motor(NAN)
    , t_peu(NAN)
    , soc(std::numeric_limits<uint8_t>::max())
    , motor(std::numeric_limits<uint16_t>::max())
    , v_line1(NAN)
    , v_line2(NAN)
    , v_line3(NAN)
    , i_line1(NAN)
    , i_line2(NAN)
    , i_line3(NAN)
    , p_line(NAN)
    , v_aps(NAN)
    , v_setpoint(NAN)
    , i_setpoint(std::numeric_limits<uint8_t>::max())
    , error(std::numeric_limits<uint8_t>::max())
    {}

template <class _Tp>
bool VehicleData::isValid(_Tp value)
{
    return value != std::numeric_limits<_Tp>::max();
}

bool VehicleData::isValid(float value)
{
    return !std::isnan(value);
}