#include "Messaging/JsonHandler.h"
#include "Vehicle/VehicleData.h"
#include "Positioning/Location.h"

using namespace Messaging;

std::string JsonHandler::generateMessage(Vehicle::VehicleData vehicleData, Positioning::Location locationData)
{
	const size_t capacity = JSON_ARRAY_SIZE(24) + 24*JSON_OBJECT_SIZE(1) + 26*JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(26);
	DynamicJsonDocument doc(capacity);

	doc["version-api"] = "1.0";
	doc["timestamp"] = "YYYY-MM-DDTHH:MM:SS+HH:MM";
	doc["identifier"] = "lotus-001";

	JsonObject data = doc.createNestedObject("data");

	JsonObject data_v_min = data.createNestedObject("v_min");
	data_v_min["value"] = vehicleData.v_min;
	data_v_min["unit"] = "V";

	JsonObject data_v_max = data.createNestedObject("v_max");
	data_v_max["value"] = vehicleData.v_max;
	data_v_max["unit"] = "V";

	JsonObject data_v_avg = data.createNestedObject("v_avg");
	data_v_avg["value"] = vehicleData.v_avg;
	data_v_avg["unit"] = "V";

	JsonObject data_i_batt = data.createNestedObject("i_batt");
	data_i_batt["value"] = vehicleData.i_batt;
	data_i_batt["unit"] = "A";

	JsonObject data_i_acc = data.createNestedObject("i_acc");
	data_i_acc["value"] = vehicleData.i_acc;
	data_i_acc["unit"] = "A";

	JsonObject data_t_min = data.createNestedObject("t_min");
	data_t_min["value"] = vehicleData.t_min;
	data_t_min["unit"] = "ºC";

	JsonObject data_t_max = data.createNestedObject("t_max");
	data_t_max["value"] = vehicleData.t_max;
	data_t_max["unit"] = "ºC";

	JsonObject data_t_avg = data.createNestedObject("t_avg");
	data_t_avg["value"] = vehicleData.t_avg;
	data_t_avg["unit"] = "ºC";

	JsonObject data_t_motor = data.createNestedObject("t_motor");
	data_t_motor["value"] = vehicleData.t_motor;
	data_t_motor["unit"] = "ºC";

	JsonObject data_t_peu = data.createNestedObject("t_peu");
	data_t_peu["value"] = vehicleData.t_peu;
	data_t_peu["unit"] = "ºC";

	JsonObject data_soc = data.createNestedObject("soc");
	data_soc["value"] = vehicleData.soc;
	data_soc["unit"] = "%";

	JsonObject data_motor = data.createNestedObject("motor");
	data_motor["value"] = vehicleData.motor;
	data_motor["unit"] = "RPM";

	JsonObject data_v_line1 = data.createNestedObject("v_line1");
	data_v_line1["value"] = vehicleData.v_line1;
	data_v_line1["unit"] = "V";

	JsonObject data_v_line2 = data.createNestedObject("v_line2");
	data_v_line2["value"] = vehicleData.v_line2;
	data_v_line2["unit"] = "V";

	JsonObject data_v_line3 = data.createNestedObject("v_line3");
	data_v_line3["value"] = vehicleData.v_line3;
	data_v_line3["unit"] = "V";

	JsonObject data_i_line1 = data.createNestedObject("i_line1");
	data_i_line1["value"] = vehicleData.i_line1;
	data_i_line1["unit"] = "A";

	JsonObject data_i_line2 = data.createNestedObject("i_line2");
	data_i_line2["value"] = vehicleData.i_line2;
	data_i_line2["unit"] = "A";

	JsonObject data_i_line3 = data.createNestedObject("i_line3");
	data_i_line3["value"] = vehicleData.i_line3;
	data_i_line3["unit"] = "A";

	JsonObject data_p_line = data.createNestedObject("p_line");
	data_p_line["value"] = "number";
	data_p_line["unit"] = "kW";

	JsonObject data_v_aps = data.createNestedObject("v_aps");
	data_v_aps["value"] = vehicleData.v_aps;
	data_v_aps["unit"] = "V";

	JsonObject data_v_setpoint = data.createNestedObject("v_setpoint");
	data_v_setpoint["value"] = vehicleData.v_setpoint;
	data_v_setpoint["unit"] = "V";

	JsonObject data_i_setpoint = data.createNestedObject("i_setpoint");
	data_i_setpoint["value"] = vehicleData.i_setpoint;
	data_i_setpoint["unit"] = "kW";

	JsonObject data_error = data.createNestedObject("error");
	data_error["value"] = vehicleData.error;
	data_error["unit"] = "error_codes";

	JsonObject data_longitude = data.createNestedObject("longitude");
	data_longitude["value"] = locationData.longitude;
	data_longitude["unit"] = "DDDMM.MMMM";

	JsonObject data_latitude = data.createNestedObject("latitude");
	data_latitude["value"] = locationData.latitude;
	data_latitude["unit"] = "DDDMM.MMMM";

	JsonObject data_altitude = data.createNestedObject("altitude");
	data_altitude["value"] = locationData.altitude;
	data_altitude["unit"] = "DDDMM.MMMM";

	JsonArray sensors = doc.createNestedArray("sensors");
	JsonObject sensors_0 = sensors.createNestedObject();
	sensors_0["v_min"] = vehicleData.isValid(vehicleData.v_min);
	JsonObject sensors_1 = sensors.createNestedObject();
	sensors_1["v_max"] = vehicleData.isValid(vehicleData.v_max);
	JsonObject sensors_2 = sensors.createNestedObject();
	sensors_2["v_avg"] = vehicleData.isValid(vehicleData.v_avg);
	JsonObject sensors_3 = sensors.createNestedObject();
	sensors_3["i_batt"] = vehicleData.isValid(vehicleData.i_batt);
	JsonObject sensors_4 = sensors.createNestedObject();
	sensors_4["i_motor"] = vehicleData.isValid(vehicleData.i_motor);
	JsonObject sensors_5 = sensors.createNestedObject();
	sensors_5["i_acc"] = vehicleData.isValid(vehicleData.i_acc);
	JsonObject sensors_6 = sensors.createNestedObject();
	sensors_6["t_min"] = vehicleData.isValid(vehicleData.t_min);
	JsonObject sensors_7 = sensors.createNestedObject();
	sensors_7["t_max"] = vehicleData.isValid(vehicleData.t_max);
	JsonObject sensors_8 = sensors.createNestedObject();
	sensors_8["t_avg"] = vehicleData.isValid(vehicleData.t_avg);
	JsonObject sensors_9 = sensors.createNestedObject();
	sensors_9["t_motor"] = vehicleData.isValid(vehicleData.t_motor);
	JsonObject sensors_10 = sensors.createNestedObject();
	sensors_10["t_peu"] = vehicleData.isValid(vehicleData.t_peu);
	JsonObject sensors_11 = sensors.createNestedObject();
	sensors_11["soc"] = vehicleData.isValid(vehicleData.soc);
	JsonObject sensors_12 = sensors.createNestedObject();
	sensors_12["motor"] = vehicleData.isValid(vehicleData.motor);
	JsonObject sensors_13 = sensors.createNestedObject();
	sensors_13["v_line1"] = vehicleData.isValid(vehicleData.v_line1);
	JsonObject sensors_14 = sensors.createNestedObject();
	sensors_14["v_line2"] = vehicleData.isValid(vehicleData.v_line2);
	JsonObject sensors_15 = sensors.createNestedObject();
	sensors_15["v_line3"] = vehicleData.isValid(vehicleData.v_line3);
	JsonObject sensors_16 = sensors.createNestedObject();
	sensors_16["i_line1"] = vehicleData.isValid(vehicleData.i_line1);
	JsonObject sensors_17 = sensors.createNestedObject();
	sensors_17["i_line2"] = vehicleData.isValid(vehicleData.i_line2);
	JsonObject sensors_18 = sensors.createNestedObject();
	sensors_18["i_line3"] = vehicleData.isValid(vehicleData.i_line3);
	JsonObject sensors_19 = sensors.createNestedObject();
	sensors_19["p_line"] = vehicleData.isValid(vehicleData.p_line);
	JsonObject sensors_20 = sensors.createNestedObject();
	sensors_20["v_aps"] = vehicleData.isValid(vehicleData.v_aps);
	JsonObject sensors_21 = sensors.createNestedObject();
	sensors_21["v_setpoint"] = vehicleData.isValid(vehicleData.v_setpoint);
	JsonObject sensors_22 = sensors.createNestedObject();
	sensors_22["i_setpoint"] = vehicleData.isValid(vehicleData.i_setpoint);
	JsonObject sensors_23 = sensors.createNestedObject();
	sensors_23["error"] = vehicleData.isValid(vehicleData.error);
	// JsonObject sensors_24 = sensors.createNestedObject();
	// sensors_24["longitude"] = tba
	// JsonObject sensors_25 = sensors.createNestedObject();
	// sensors_25["latitude"] = tba
	// JsonObject sensors_26 = sensors.createNestedObject();
	// sensors_26["altitude"] = tba

	char json_string[capacity];
	serializeJson(doc, json_string);
	std::string output = json_string;
	return output;
}

enum command_types {
    charge_vehicle,
    reverse_charge_vehicle,
	stop_charging_vehicle,
	error
};

command_types hashit (std::string const& inString) {
    if (inString == "charge_vehicle") return charge_vehicle;
    if (inString == "reverse_charge_vehicle") return reverse_charge_vehicle;
	if (inString == "stop_charging_vehicle") return stop_charging_vehicle;
	return error;
}

std::shared_ptr<Command> JsonHandler::parseMessage(std::string message)
{
	std::shared_ptr<Command> output;

	const size_t capacity = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(2) + 50;
	DynamicJsonDocument doc(capacity);

	deserializeJson(doc, message);

	const char* commandChar = doc["command"];

	const char* paramCurrentChar = doc["params"]["current"];

	std::string command = commandChar;
	std::string paramCurrent = paramCurrentChar;
	
	switch (hashit(command)){
		case charge_vehicle:
			output = this->commands.find("charge_vehicle")->second;
			output->parseParams(paramCurrent);
			return output;
		case reverse_charge_vehicle:
			output = this->commands.find("reverse_charge_vehicle")->second;
			output->parseParams(paramCurrent);
			return output;
		case stop_charging_vehicle:
			output = this->commands.find("stop_charging_vehicle")->second;
			return output;
		case error:
			return 0;	
		}
	return 0;
}
