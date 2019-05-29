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
	bool vmsErrorState;
	bool networkErrorState;

public:
	Notifier(std::unique_ptr<ColorLight> colorLight);

	void setVmsError();

	void setNetworkError();

	void off();
};
}

#endif
