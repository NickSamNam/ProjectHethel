#include "Vehicle/VehicleClient.h"
#include "Networking/NetworkClient.h"
#include "Positioning/LocationProvider.h"
#include "Notifying/Notifier.h"
#include "Messaging/JsonHandler.h"

using namespace Vehicle;
using namespace Networking;
using namespace Positioning;
using namespace Notifying;
using namespace Messaging;

VehicleClient vehicle;
NetworkClient network;
LocationProvider *location;
Notifier notifier;
JsonHandler messageHandler;

void setup()
{
	Serial.begin(9600);
	Serial1.clear();
	Serial1.setTX(1);
	Serial1.setRX(0);
	Serial1.begin(9600);
	location = new LocationProvider();
	
}

void loop()
{
	Serial.println("long:");
	Serial.println(location->getLocation().longitude);
	delay(1000);
}
