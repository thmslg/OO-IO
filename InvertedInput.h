#ifndef INPUTINVERTER_H_
#define INPUTINVERTER_H_

#include "Input.h"

class InvertedInput: public Input
{
public:
	InvertedInput(Input & inputToInvert);
	virtual ~InvertedInput(){}
	//--------------------------------------------------------------------------------------------------------
	//! \pre See base class
	//! \post See base class
	virtual bool GetState() const;
private:
	//--------------------------------------------------------------------------------------------------------
	//! \pre
	//! \post
	void InputToInvertHasChanged(bool newSTate);

	//--------------------------------------------------------------------------------------------------------
	Input & _inputToInvert;
	//--------------------------------------------------------------------------------------------------------
	TypedDelegate<InvertedInput> _delegateToInput;
};

#endif /* INPUTINVERTER_H_ */
