#ifndef JSONPARAMS_H
#define JSONPARAMS_H

#include <string>

namespace Messaging
{
class JsonParams
{
public:
	virtual void parseParams(std::string params);
};
}

#endif
