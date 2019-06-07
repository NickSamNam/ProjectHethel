#ifndef COMMAND_H
#define COMMAND_H

namespace Messaging
{
class Command
{
public:
	virtual ~Command();

	virtual void execute() = 0; //Wordt aangeroepen in de main en voert het commando uit.
};
}

#endif
