#ifndef COMMAND_H
#define COMMAND_H
#include <string>

namespace Messaging
{
class Command
{
public:
	virtual ~Command(){};

	virtual void execute() = 0;

	virtual void parseParams(std::string params) = 0;
};
}

#endif
