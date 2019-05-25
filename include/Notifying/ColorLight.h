#ifndef COLORLIGHT_H
#define COLORLIGHT_H

namespace Notifying
{
class ColorLight
{
public:
	void virtual off() = 0;

	void virtual on(int r, int g, int b) = 0;
};
}

#endif
