#ifndef COMMAND_H
#define COMMAND_H

#include <WString.h>
#include <map>

namespace Messaging
{
class Command
{
public:
	virtual ~Command(){};

	virtual void execute() = 0;

	virtual void parseParams(std::map<String, String> params) = 0;
};
}

#endif
