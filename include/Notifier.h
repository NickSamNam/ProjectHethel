#ifndef NOTIFIER_H
#define NOTIFIER_H

class Notifier
{

private:
	bool vmsErrorState;
	bool networkErrorState;

public:
	void setVmsError(bool state);

	void setNetworkError(bool state);

private:
	/**
	 * Is called after each setter, executes the needed RGB config.
	 */
	void updateState();
};

#endif
