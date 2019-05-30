#ifndef RGBLED_H
#define RGBLED_H

#include <Arduino.h>
#include "ColorLight.h"

namespace Notifying
{
class RgbLed : public ColorLight
{
private:
	int redPin;
	int greenPin;
	int bluePin;

public:
	RgbLed(int redPin, int greenPin, int bluePin);
	
	void off();

	void on(int r, int g, int b);
};
}

#endif
