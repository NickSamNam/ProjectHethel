#include "Notifying/Notifier.h"

using namespace Notifying;

Notifier::Notifier(std::unique_ptr<ColorLight> colorLight) : colorLight(std::move(colorLight)) {}

void Notifier::setVmsError(bool state)
{
	if(state){
		this->colorLight->on(255, 165, 0);
	} else
	{
		this->colorLight->off();
	}
}

void Notifier::setNetworkError(bool state)
{
	if(state){
		this->colorLight->on(255, 0, 0);
	} else
	{
		this->colorLight->off();
	}
}
