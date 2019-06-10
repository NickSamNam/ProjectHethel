#include <memory>
#include <Arduino.h>
#include "Vehicle/VehicleClient.h"
#include "Vehicle/AcPropulsion.h"
#include "Networking/NetworkClient.h"
#include "Positioning/LocationProvider.h"
#include "Notifying/Notifier.h"
#include "Messaging/JsonHandler.h"

using namespace Vehicle;
using namespace Networking;
using namespace Positioning;
using namespace Notifying;
using namespace Messaging;

#define VEHICLE_SERIAL Serial3
#define MAX_CHARGING_CURRENT 6
#define MAX_REVERSE_CHARGING_CURRENT 6

std::shared_ptr<VehicleClient> vehicle;
std::shared_ptr<NetworkClient> network;
std::shared_ptr<LocationProvider> location;
std::shared_ptr<Notifier> notifier;
std::shared_ptr<JsonHandler> messageHandler;

void setup()
{
	// TODO - implement setup
	vehicle = std::make_shared<VehicleClient>(
		std::move(std::make_unique<AcPropulsion>(
			std::move(std::make_unique<HardwareSerial>(
				VEHICLE_SERIAL)),
			MAX_CHARGING_CURRENT, MAX_REVERSE_CHARGING_CURRENT)));
}

void loop()
{
	// TODO - implement loop
}
