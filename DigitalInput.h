#ifndef DIGITALINPUT_H_
#define DIGITALINPUT_H_

//--------------------------------------------------------------------------------------------------------
// This class is responsible for encapsulate an Digital input behavior.
// An input could be a two state : high or low state.
// We decided to NOT redefine the type DigitalState, but use bool type instead.
// LowState = false and HighState = true
class DigitalInput
{
public:

	explicit DigitalInput()
	{
	}

	virtual ~DigitalInput(){}

	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post Get the current state of the input.
	virtual bool GetState() const = 0;
};


#endif /* DIGITALINPUT_H_ */
