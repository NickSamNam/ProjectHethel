#include "Notifying/Notifier.h"

using namespace Notifying;

Notifier::Notifier(ColorLight* colorLight){
	this->colorLight = colorLight;
}

void Notifier::setVmsError(bool state)
{
	if(state){
		this->colorLight->on(255, 0, 0);
	} else
	{
		this->colorLight->off();
	}
}

void Notifier::setNetworkError(bool state)
{
	if(state){
		this->colorLight->on(0, 0, 255);
	} else
	{
		this->colorLight->off();
	}
}

void Notifier::updateState()
{
	// TODO - implement Notifier::updateState
	throw "Not yet implemented";
}
