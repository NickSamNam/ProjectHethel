#include <memory>
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

std::shared_ptr<VehicleClient> vehicle;
std::shared_ptr<NetworkClient> network;
std::shared_ptr<LocationProvider> location;
std::shared_ptr<Notifier> notifier;
std::shared_ptr<JsonHandler> messageHandler;

void setup()
{
	// TODO - implement setup
}

void loop()
{
	// TODO - implement loop
}
