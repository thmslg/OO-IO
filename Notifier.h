#ifndef NOTIFIER_H_
#define NOTIFIER_H_

#include "Delegate.h"
//class Delegate;

class Notifier {
public:

	// we can't use the operator new[] onto 5213 target
	// problem with linking -> we have to fix the size
	static int const maxNumberOfDelegates = 1;

	explicit Notifier();
	virtual ~Notifier();

	//--------------------------------------------------------------------------------------------------------
	//! \pre 'subscriber' NOT NULL pointer to object where 'handler' will be called
	//!	'handler' is a method pointer from subscriber. This handler has the following signature :
	//!	void handler(bool newState)
	//!	this handler will be called when event will occurs onto notifier, .
	//! \post Object pointer and handler are stored for a futur notifying.
	bool subscribe(Delegate * const handlerToCall);

	//--------------------------------------------------------------------------------------------------------
	//! \pre 'newState' will be transfered to all subscriber
	//! \post All subscriber handler will be called with the new state
	void notify(bool newState);
private:
	Delegate* _delegateContainer[maxNumberOfDelegates];
	int _delegateContainerSize;
	int _delegateContainerIndex;
};

#endif /* NOTIFIER_H_ */
