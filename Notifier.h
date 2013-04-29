#ifndef NOTIFIER_H_
#define NOTIFIER_H_

#include "Delegate.h"
#include <vector>

class Notifier {
public:
	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post  None
	explicit Notifier()
	{
	}

	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post None
	virtual ~Notifier()
	{
	}

	//--------------------------------------------------------------------------------------------------------
	//! \pre 'subscriber' NOT NULL pointer to object where 'handler' will be called
	//!	'handler' is a method pointer from subscriber. This handler has the following signature :
	//!	void handler(bool newState)
	//!	this handler will be called when event will occurs onto notifier, .
	//! \post Object pointer and handler are stored for a futur notifying.
	void subscribe(Delegate * const delegateToInvoke);

	//--------------------------------------------------------------------------------------------------------
	//! \pre 'newState' will be transfered to all subscriber
	//! \post All subscriber handler will be called with the new state
	void notifyListeners(bool newState);

private:
	std::vector<Delegate*> _delegateContainer;
};

#endif /* NOTIFIER_H_ */
