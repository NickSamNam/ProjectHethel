#include <ArduinoJson.h>

#include "Messaging/JsonHandler.h"
#include "Vehicle/VehicleData.h"
#include "Positioning/Location.h"

#define VERSION_API "1.0"
#define IDENTIFIER "lotus-001"

#define GENERATE_JSON_LOOSE_OBJECTS 5
#define GENERATE_JSON_ARRAY_ELEMENTS 29
#define GENERATE_JSON_DATA_OBJECT_ELEMENTS 2
#define GENERATE_JSON_SENSORS_OBJECT_ELEMENTS 1
#define GENERATE_JSON_MARGIN 1000

#define PARSE_JSON_COMMAND_OBJECT_SIZE 1
#define PARSE_JSON_PARAMS_OBJECT_SIZE 2
#define PARSE_JSON_MARGIN 50

#define JSON_ARRAY_SIZE(NUMBER_OF_ELEMENTS) \
  ((NUMBER_OF_ELEMENTS) * sizeof(ARDUINOJSON_NAMESPACE::VariantSlot))
#define JSON_OBJECT_SIZE(NUMBER_OF_ELEMENTS) \
  ((NUMBER_OF_ELEMENTS) * sizeof(ARDUINOJSON_NAMESPACE::VariantSlot))
using namespace Messaging;

String reformatLocationTimeStamp(long timestamp){
	char buffer[25];
	int 
	h1=timestamp / 100000 % 10,
	h2=timestamp / 10000 % 10,
	m1=timestamp / 1000 % 10,
	m2=timestamp / 100 % 10,
	s1=timestamp / 10 % 10,
	s2=timestamp % 10;

	sprintf(buffer, "0000-00-00T%i%i:%i%i:%i%i+00:00", h1, h2, m1, m2, s1, s2);
	return buffer;
}

String concatenateCardinalDirection(long coordinates, char direction){
	char buffer[25];
	sprintf(buffer, "%lu %c", coordinates, direction);
	return buffer;
}

String JsonHandler::generateMessage(Vehicle::VehicleData vehicleData, Positioning::Location locationData)
{
	const size_t capacity = JSON_ARRAY_SIZE(GENERATE_JSON_ARRAY_ELEMENTS) + GENERATE_JSON_ARRAY_ELEMENTS*JSON_OBJECT_SIZE(GENERATE_JSON_SENSORS_OBJECT_ELEMENTS) + GENERATE_JSON_ARRAY_ELEMENTS*JSON_OBJECT_SIZE(GENERATE_JSON_DATA_OBJECT_ELEMENTS) + JSON_OBJECT_SIZE(GENERATE_JSON_LOOSE_OBJECTS) + JSON_OBJECT_SIZE(GENERATE_JSON_DATA_OBJECT_ELEMENTS) + GENERATE_JSON_MARGIN;
	DynamicJsonDocument doc(capacity);

	doc["version-api"] = VERSION_API;
	doc["timestamp"] = reformatLocationTimeStamp(locationData.timestamp);
	doc["identifier"] = IDENTIFIER;

	JsonObject data = doc.createNestedObject("data");

	JsonObject data_v_min = data.createNestedObject("v_min");
	data_v_min["value"] = vehicleData.v_min;
	data_v_min["unit"] = Vehicle::VehicleData::Units::volt;

	JsonObject data_v_max = data.createNestedObject("v_max");
	data_v_max["value"] = vehicleData.v_max;
	data_v_max["unit"] = Vehicle::VehicleData::Units::volt;

	JsonObject data_v_avg = data.createNestedObject("v_avg");
	data_v_avg["value"] = vehicleData.v_avg;
	data_v_avg["unit"] = Vehicle::VehicleData::Units::volt;

	JsonObject data_i_batt = data.createNestedObject("i_batt");
	data_i_batt["value"] = vehicleData.i_batt;
	data_i_batt["unit"] = Vehicle::VehicleData::Units::ampere;

	JsonObject data_i_acc = data.createNestedObject("i_acc");
	data_i_acc["value"] = vehicleData.i_acc;
	data_i_acc["unit"] = Vehicle::VehicleData::Units::ampere;

	JsonObject data_t_min = data.createNestedObject("t_min");
	data_t_min["value"] = vehicleData.t_min;
	data_t_min["unit"] = Vehicle::VehicleData::Units::celsius;

	JsonObject data_t_max = data.createNestedObject("t_max");
	data_t_max["value"] = vehicleData.t_max;
	data_t_max["unit"] = Vehicle::VehicleData::Units::celsius;

	JsonObject data_t_avg = data.createNestedObject("t_avg");
	data_t_avg["value"] = vehicleData.t_avg;
	data_t_avg["unit"] = Vehicle::VehicleData::Units::celsius;

	JsonObject data_t_motor = data.createNestedObject("t_motor");
	data_t_motor["value"] = vehicleData.t_motor;
	data_t_motor["unit"] = Vehicle::VehicleData::Units::celsius;

	JsonObject data_t_peu = data.createNestedObject("t_peu");
	data_t_peu["value"] = vehicleData.t_peu;
	data_t_peu["unit"] = Vehicle::VehicleData::Units::celsius;

	JsonObject data_soc = data.createNestedObject("soc");
	data_soc["value"] = vehicleData.soc;
	data_soc["unit"] = Vehicle::VehicleData::Units::percentage;

	JsonObject data_motor = data.createNestedObject("motor");
	data_motor["value"] = vehicleData.motor;
	data_motor["unit"] = Vehicle::VehicleData::Units::rotations_per_minute;

	JsonObject data_v_line1 = data.createNestedObject("v_line1");
	data_v_line1["value"] = vehicleData.v_line1;
	data_v_line1["unit"] = Vehicle::VehicleData::Units::volt;

	JsonObject data_v_line2 = data.createNestedObject("v_line2");
	data_v_line2["value"] = vehicleData.v_line2;
	data_v_line2["unit"] = Vehicle::VehicleData::Units::volt;

	JsonObject data_v_line3 = data.createNestedObject("v_line3");
	data_v_line3["value"] = vehicleData.v_line3;
	data_v_line3["unit"] = Vehicle::VehicleData::Units::volt;

	JsonObject data_i_line1 = data.createNestedObject("i_line1");
	data_i_line1["value"] = vehicleData.i_line1;
	data_i_line1["unit"] = Vehicle::VehicleData::Units::ampere;

	JsonObject data_i_line2 = data.createNestedObject("i_line2");
	data_i_line2["value"] = vehicleData.i_line2;
	data_i_line2["unit"] = Vehicle::VehicleData::Units::ampere;

	JsonObject data_i_line3 = data.createNestedObject("i_line3");
	data_i_line3["value"] = vehicleData.i_line3;
	data_i_line3["unit"] = Vehicle::VehicleData::Units::ampere;

	JsonObject data_p_line = data.createNestedObject("p_line");
	data_p_line["value"] = vehicleData.p_line;
	data_p_line["unit"] = Vehicle::VehicleData::Units::kilo_watt;

	JsonObject data_v_aps = data.createNestedObject("v_aps");
	data_v_aps["value"] = vehicleData.v_aps;
	data_v_aps["unit"] = Vehicle::VehicleData::Units::volt;

	JsonObject data_v_setpoint = data.createNestedObject("v_setpoint");
	data_v_setpoint["value"] = vehicleData.v_setpoint;
	data_v_setpoint["unit"] = Vehicle::VehicleData::Units::volt;

	JsonObject data_i_setpoint = data.createNestedObject("i_setpoint");
	data_i_setpoint["value"] = vehicleData.i_setpoint;
	data_i_setpoint["unit"] = Vehicle::VehicleData::Units::kilo_watt;

	JsonObject data_error = data.createNestedObject("error");
	data_error["value"] = vehicleData.error;
	data_error["unit"] = Vehicle::VehicleData::Units::error_codes;

	JsonObject data_longitude = data.createNestedObject("longitude");
	data_longitude["value"] = concatenateCardinalDirection(locationData.longitude, locationData.directionLong);
	data_longitude["unit"] = Positioning::Location::Units::DDDmm_mmmm_C;

	JsonObject data_latitude = data.createNestedObject("latitude");
	data_latitude["value"] = concatenateCardinalDirection(locationData.latitude, locationData.directionLat);
	data_latitude["unit"] = Positioning::Location::Units::DDmm_mmmm_C;

	JsonObject data_altitude = data.createNestedObject("altitude");
	data_altitude["value"] = locationData.altitude;
	data_altitude["unit"] = Positioning::Location::Units::meters;

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
	JsonObject sensors_24 = sensors.createNestedObject();
	sensors_24["longitude"] = locationData.isValid(locationData.longitude);
	JsonObject sensors_25 = sensors.createNestedObject();
	sensors_25["latitude"] = locationData.isValid(locationData.latitude);
	JsonObject sensors_26 = sensors.createNestedObject();
	sensors_26["altitude"] = locationData.isValid(locationData.altitude);
	
	String output;
	serializeJson(doc, output);
	
	return output;
}

std::shared_ptr<Command> JsonHandler::parseMessage(String message)
{
	const size_t capacity = JSON_OBJECT_SIZE(PARSE_JSON_COMMAND_OBJECT_SIZE) + JSON_OBJECT_SIZE(PARSE_JSON_PARAMS_OBJECT_SIZE) + PARSE_JSON_MARGIN;
	DynamicJsonDocument doc(capacity);

	deserializeJson(doc, message);

	const char* commandName = doc["command"];

	std::map<String, String> commandParams;

	for (JsonPair kv : doc["params"].as<JsonObject>())
	{
		commandParams.insert({kv.key().c_str(), kv.value().as<char*>()});
	}

	std::shared_ptr<Command> command = commands.find(commandName)->second;
	command->parseParams(commandParams);
	return command;
}
