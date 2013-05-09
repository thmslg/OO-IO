#ifndef LISTENABLESAMPLEDINPUT_H_
#define LISTENABLESAMPLEDINPUT_H_

#include "Samplable.h"
#include "DigitalInput.h"

//Forward declaration
class ListenerSubject;
class DelegateBooleanParameter;

class ListenableSampledInput: public Samplable, public DigitalInput
{
public:
	ListenableSampledInput(DigitalInput & inputToSample);

	virtual ~ListenableSampledInput(){}
	//--------------------------------------------------------------------------------------------------------
	//! \pre See base class DigitalInput
	//! \post See base class DigitalInput
	virtual bool GetState() const;
	//--------------------------------------------------------------------------------------------------------
	//! \pre See base class Samplable
	//! \post See base class Samplable
	virtual void Acquire();
	//--------------------------------------------------------------------------------------------------------
	//! \pre
	//! \post
	void addListener(DelegateBooleanParameter & observerHandler);
private:
	DigitalInput & _inputToSample;
	bool _currentOfficialState;
	ListenerSubject _notifier;
};

#endif /* LISTENABLESAMPLEDINPUT_H_ */
