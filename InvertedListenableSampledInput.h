#ifndef INVERTEDLISTENABLESAMPLEDINPUT_H_
#define INVERTEDLISTENABLESAMPLEDINPUT_H_

#include "DigitalInput.h"
#include "ListenableSampledInput.h"
#include "utils/DelegateBooleanParameter.h"
#include "ListenerSubject.h"

class InvertedListenableSampledInput: public DigitalInput
{
public:
	//--------------------------------------------------------------------------------------------------------
	//! \pre
	//! \post
	InvertedListenableSampledInput(ListenableSampledInput & inputToInvert);
	//--------------------------------------------------------------------------------------------------------
	virtual ~InvertedListenableSampledInput(){}
	//--------------------------------------------------------------------------------------------------------
	//! \pre See base class
	//! \post See base class
	virtual bool GetState() const;
	//--------------------------------------------------------------------------------------------------------
	//! \pre
	//! \post
	void addListener(DelegateBooleanParameter & listenerHandlerToAdd);
private:
	//--------------------------------------------------------------------------------------------------------
	//! \pre
	//! \post
	void InputToInvertHasChanged(bool newSTate);

	//--------------------------------------------------------------------------------------------------------
	ListenableSampledInput & _inputToInvert;
	//--------------------------------------------------------------------------------------------------------
	TypedDelegateBooleanParameter<InvertedListenableSampledInput> _delegateToInput;
	//--------------------------------------------------------------------------------------------------------
	ListenerSubject _notifier;
};

#endif /* INVERTEDLISTENABLESAMPLEDINPUT_H_ */
