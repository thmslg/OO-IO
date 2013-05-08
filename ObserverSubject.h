#ifndef NOTIFIER_H_
#define NOTIFIER_H_

#include "DelegateBooleanParameter.h" // to notify observers.
#include <vector> // to store observers

//--------------------------------------------------------------------------------------------------------
//! This class is responsible to notify observers, previously subscribed to it.
//! It's the subject part of the Observer pattern.
//! This implementation avoid you to inherit a lot of interface. To subscribe to the subject you only
//! have to subscribe with a particular signature method.
//!
//! For example his implementation is more understandable for me when you have to observe a lot of different
//! Inputs !
class ObserverSubject {
public:
	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post  None
	//! avoid copy
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
	//!	'handler' is a method pointer from subscriber instance.
	//! \post Object pointer and handler are stored for a futur notifying.
	void subscribe(DelegateBooleanParameter * const delegateToInvokeWhenNotifyIsNeeded);

	//--------------------------------------------------------------------------------------------------------
	//! \pre 'newState' will be transfered to all subscriber
	//! \post All subscriber handler will be called with the new state
	void notifyObserver(bool newState);

private:

	//!	Theses handlers will be called when notifyObserver( newState) will be called .
	std::vector<DelegateBooleanParameter*> _observerList;
};

#endif /* NOTIFIER_H_ */
