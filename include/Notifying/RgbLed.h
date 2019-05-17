#ifndef RGBLED_H
#define RGBLED_H

#include "ColorLight.h"

namespace Notifying
{
class RgbLed : ColorLight
{


public:
	void off();

	void on(int r, int g, int b);
};
}

#endif
