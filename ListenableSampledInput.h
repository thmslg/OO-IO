#ifndef LISTENABLESAMPLEDINPUT_H_
#define LISTENABLESAMPLEDINPUT_H_

#include "Samplable.h"
#include "DigitalInput.h"

//Forward declaration
class ListenerSubject;
class DelegateBooleanParameter;

//--------------------------------------------------------------------------------------------------------
// This class is an ellaborated implementation of digital input. It could be considered as the subject
// of the Listener pattern. So you can subscribe to it, to be aware of DigitalInput state change.
class ListenableSampledInput: public Samplable, public DigitalInput
{
public:
	//--------------------------------------------------------------------------------------------------------
	//! \pre 'inputToSample' should be ready to "GetState"
	//! \post None
	ListenableSampledInput(DigitalInput & inputToSample);

	//--------------------------------------------------------------------------------------------------------
	virtual ~ListenableSampledInput();

	//--------------------------------------------------------------------------------------------------------
	//! \pre See base class DigitalInput
	//! \post See base class DigitalInput
	virtual bool GetState() const;

	//--------------------------------------------------------------------------------------------------------
	//! \pre See base class Samplable
	//! \post See base class Samplable
	virtual void Acquire();

	//--------------------------------------------------------------------------------------------------------
	//! \pre 'listenerHandler' should be called at any time after call of this method.
	//! \post
	void addListener(DelegateBooleanParameter * const listenerHandler);
private:
	DigitalInput & _inputToSample;
	bool _currentOfficialState;
	ListenerSubject * const _notifier;
};

#endif /* LISTENABLESAMPLEDINPUT_H_ */
