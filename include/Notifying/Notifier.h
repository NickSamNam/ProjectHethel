#ifndef NOTIFIER_H
#define NOTIFIER_H

#include <memory>
#include "Notifying/ColorLight.h"

namespace Notifying
{
class Notifier
{
private:
	std::unique_ptr<ColorLight> colorLight; //Notifier has a ColorLight.

public:
	Notifier(std::unique_ptr<ColorLight> colorLight);

	Notifier(const Notifier &) = delete;

	Notifier &operator=(const Notifier &) = delete;

	void setVmsError();

	void setNetworkError();

	void off();
};
}

#endif
