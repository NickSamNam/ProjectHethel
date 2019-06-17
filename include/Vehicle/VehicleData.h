#ifndef VEHICLEDATA_H
#define VEHICLEDATA_H

#include <stdint.h>
#include <string.h>

namespace Vehicle
{
struct VehicleData
{

public:
	uint32_t timestamp;
	float v_min;
	float v_max;
	float v_avg;
	float i_batt;
	float i_motor;
	float i_acc;
	float t_min;
	float t_max;
	float t_avg;
	float t_motor;
	float t_peu;
	uint8_t soc;
	uint16_t motor;
	float v_line1;
	float v_line2;
	float v_line3;
	float i_line1;
	float i_line2;
	float i_line3;
	float p_line;
	float v_aps;
	float v_setpoint;
	uint8_t i_setpoint;
	uint8_t error;

	VehicleData();

	template <class _Tp>
	static bool isValid(_Tp value);

	static bool isValid(float value);

	static const struct Units {
	const std::string volt = "V";
	const std::string ampere = "A";
	const std::string celsius = "ºC";
	const std::string percentage = "%";
	const std::string rotations_per_minute = "RPM";
	const std::string kilo_watt = "kW";
	const std::string error_codes = "error_codes";
  } units;
};
}

#endif
