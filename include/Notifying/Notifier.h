#ifndef NOTIFIER_H
#define NOTIFIER_H

#include "Notifying/ColorLight.h"

namespace Notifying
{
class Notifier
{
private:
	ColorLight colorLight; //Notifier has a ColorLight.
	bool vmsErrorState;
	bool networkErrorState;

public:
	Notifier(ColorLight colorLight1);

	void setVmsError(bool state);

	void setNetworkError(bool state);

private:
	/**
	 * Is called after each setter, executes the needed RGB config.
	 */
	void updateState();
};
}

#endif
