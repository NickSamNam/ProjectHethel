#include "Notifying/Notifier.h"

using namespace Notifying;

Notifier::Notifier(std::unique_ptr<ColorLight> colorLight) : colorLight(std::move(colorLight)) {}

void Notifier::setVmsError()
{
	this->colorLight->on(255, 165, 0);
}

void Notifier::setNetworkError()
{
	this->colorLight->on(255, 0, 0);
}

void Notifier::off(){
	this->colorLight->off();
}
