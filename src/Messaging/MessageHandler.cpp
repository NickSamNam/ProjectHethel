#include "Messaging/MessageHandler.h"
#include "Messaging/Commands/Command.h"

using namespace Messaging;

void MessageHandler::addCommand(std::string name, Command &command)
{
	this->commands.insert({name, command});
}
