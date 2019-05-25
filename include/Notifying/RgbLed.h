#ifndef RGBLED_H
#define RGBLED_H

#include <Arduino.h>
#include "ColorLight.h"

namespace Notifying
{
class RgbLed : ColorLight
{

private:
	void setup();

public:
	void off();

	void on(int r, int g, int b);
};
}

#endif
