#include <memory>
#include <Arduino.h>
#include "Vehicle/VehicleClient.h"
#include "Vehicle/AcPropulsion.h"
#include "Networking/NetworkClient.h"
#include "Positioning/LocationProvider.h"
#include "Notifying/Notifier.h"
#include "Notifying/RgbLed.h"
#include "Messaging/JsonHandler.h"

using namespace Vehicle;
using namespace Networking;
using namespace Positioning;
using namespace Notifying;
using namespace Messaging;

#define USB_SERIAL_BAUD 9600

#define VEHICLE_SERIAL &Serial3
#define MAX_CHARGING_CURRENT 6
#define MAX_REVERSE_CHARGING_CURRENT 6
#define VEHICLE_TIMEOUT_THRESHOLD 3000

#define LED_PIN_RED 23
#define LED_PIN_GREEN 22
#define LED_PIN_BLUE 21

std::shared_ptr<VehicleClient> vehicle;
std::shared_ptr<NetworkClient> network;
std::shared_ptr<LocationProvider> location;
std::shared_ptr<Notifier> notifier;
std::shared_ptr<JsonHandler> messageHandler;

uint32_t prevVehicleMillis = 0;

void setup()
{
	// Prevent linking error.
	Serial.begin(USB_SERIAL_BAUD);
	Serial.println(F("Started"));

	// TODO - implement setup
	vehicle = std::make_shared<VehicleClient>(
		std::move(std::make_unique<AcPropulsion>(
			VEHICLE_SERIAL,
			MAX_CHARGING_CURRENT, MAX_REVERSE_CHARGING_CURRENT)));
	notifier = std::make_shared<Notifier>(
		std::move(std::make_unique<RgbLed>(LED_PIN_RED,	LED_PIN_BLUE, LED_PIN_GREEN)));
}

void loop()
{
	// TODO - implement loop
	VehicleData vehicleData = vehicle->getData();
	if (VehicleData::isValid(vehicleData.timestamp))
	{
		prevVehicleMillis = millis();
		notifier->off();
	}
	else if (millis() - prevVehicleMillis > VEHICLE_TIMEOUT_THRESHOLD)
	{
		notifier->setVmsError();
	}
}
