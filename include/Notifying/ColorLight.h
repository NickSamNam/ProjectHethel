#ifndef COLORLIGHT_H
#define COLORLIGHT_H

namespace Notifying
{
class ColorLight
{
public:
	virtual ~ColorLight();

	virtual void off() = 0;

	virtual void on(int r, int g, int b) = 0;
};
}

#endif
