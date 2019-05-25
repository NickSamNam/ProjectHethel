#include "Notifying/Notifier.h"

using namespace Notifying;

void Notifier::setVmsError(bool state)
{
	if(state){
		colorLight->on(255, 0, 0);
	} else
	{
		colorLight->off;
	}
}

void Notifier::setNetworkError(bool state)
{
	if(state){
		colorLight->on(0, 0, 255);
	} else
	{
		colorLight->off;
	}
}

void Notifier::updateState()
{
	// TODO - implement Notifier::updateState
	throw "Not yet implemented";
}
