#ifndef NOTIFIER_H_
#define NOTIFIER_H_

#include "DelegateBooleanParameter.h" // to notify observers.
#include <vector> // to store observers

class ObserverSubject {
public:
	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post  None
	explicit ObserverSubject()
	{
	}

	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post None
	virtual ~ObserverSubject()
	{
	}

	//--------------------------------------------------------------------------------------------------------
	//! \pre 'subscriber' NOT NULL pointer to object where 'handler' will be called
	//!	'handler' is a method pointer from subscriber. This handler has the following signature :
	//!	void handler(bool newState)
	//!	this handler will be called when event will occurs onto notifier, .
	//! \post Object pointer and handler are stored for a futur notifying.
	void subscribe(DelegateBooleanParameter * const delegateToInvoke);

	//--------------------------------------------------------------------------------------------------------
	//! \pre 'newState' will be transfered to all subscriber
	//! \post All subscriber handler will be called with the new state
	void notifyObserver(bool newState);

private:
	std::vector<DelegateBooleanParameter*> _observerList;
};

#endif /* NOTIFIER_H_ */
