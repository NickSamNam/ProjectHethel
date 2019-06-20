#include "Messaging/MessageHandler.h"
#include "Messaging/Commands/Command.h"

using namespace Messaging;

void MessageHandler::addCommand(String name, std::shared_ptr<Command> command)
{
	this->commands.insert({name, command});
}
