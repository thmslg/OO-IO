#ifndef SAMPLEDINPUT_H_
#define SAMPLEDINPUT_H_

#include "Samplable.h"
#include "DigitalInput.h"
#include "ObserverSubject.h"


//------------------------------------------------------------------------------------------------------------
//! The class SampledInput is responsible for hardware input representation.
//! It's the most updated view of the hardware input
//------------------------------------------------------------------------------------------------------------
class SampledInput: public Samplable,
					public DigitalInput{
public:
	//--------------------------------------------------------------------------------------------------------
	//! \pre "pinID" is a pin identifier
	//! \post Object created targeting correct input pin
	explicit SampledInput(DigitalInput & physicalInput);

	//--------------------------------------------------------------------------------------------------------
	//! \pre
	//! \post physical input reference IS NOT DELETED
	~SampledInput(){}

	//--------------------------------------------------------------------------------------------------------
	//! \pre  None
	//! \post update current state, reading low layer
	virtual void Acquire();

	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post return current state, updated during last Acquire() calling.
	//! DO NOT READ LOW LAYER
	virtual bool GetState() const;

private:
	DigitalInput & _physicalInputToSample;
	bool _officialState;
};


#endif /* SAMPLEDINPUT_H_ */
