#ifndef NOTIFIER_H
#define NOTIFIER_H

#include "Notifying/ColorLight.h"

namespace Notifying
{
class Notifier
{
private:
	ColorLight *colorLight; //Notifier has a ColorLight.
	bool vmsErrorState;
	bool networkErrorState;

public:
	Notifier(ColorLight *colorLight);

	void setVmsError(bool state);

	void setNetworkError(bool state);

	void updateState();
};
}

#endif
