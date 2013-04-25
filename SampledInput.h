#ifndef SAMPLEDINPUT_H_
#define SAMPLEDINPUT_H_

#include "Samplable.h"
#include "Input.h"


//------------------------------------------------------------------------------------------------------------
//! The class SampledInput is responsible for hardware input representation.
//! It's the most updated view of the hardware input
//------------------------------------------------------------------------------------------------------------
class SampledInput: public Samplable, public Input
{
public:
	//--------------------------------------------------------------------------------------------------------
	//! \pre "pinID" is a pin identifier
	//! \post Object created targeting correct input pin
	explicit SampledInput(bool logicalActiveState);
	~SampledInput();

	//--------------------------------------------------------------------------------------------------------
	//! \pre  None
	//! \post update current state, reading low layer
	virtual void Acquire();

	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post return current state, updated during last Acquire() calling.
	//! DO NOT READ LOW LAYER
	virtual bool GetState() const;
	virtual void ChangeInversion(bool inversion);

private:
	//! Physical level state of this input
	bool _physicalState;
	//! Logical level state of this input, we can invert the signal
	bool _isInverted;
};


#endif /* SAMPLEDINPUT_H_ */
