#include "Vehicle/VehicleClient.h"
#include "Networking/NetworkClient.h"
#include "Positioning/LocationProvider.h"
#include "Notifying/Notifier.h"
#include "Messaging/JsonHandler.h"
#include "Notifying/RgbLed.h"

using namespace Vehicle;
using namespace Networking;
using namespace Positioning;
using namespace Notifying;
using namespace Messaging;

VehicleClient vehicle;
NetworkClient network;
LocationProvider location;
JsonHandler messageHandler;

void setup()
{
	// TODO - implement setup
	//throw "Not yet implemented";
}

void loop()
{
	RgbLed rgbled;
	Notifier notifier(rgbled);
	notifier.setNetworkError(false);
	notifier.setVmsError(true);
}
