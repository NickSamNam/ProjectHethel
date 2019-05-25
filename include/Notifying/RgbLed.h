#ifndef RGBLED_H
#define RGBLED_H

#include <Arduino.h>
#include "ColorLight.h"

namespace Notifying
{
class RgbLed : ColorLight
{
private:
	int redPin = 23;
	int greenPin= 22;
	int bluePin= 21;
	void setup();

public:
	void off();

	void on(int r, int g, int b);
};
}

#endif
