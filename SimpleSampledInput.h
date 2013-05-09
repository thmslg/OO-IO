#ifndef SAMPLEDINPUT_H_
#define SAMPLEDINPUT_H_

#include "Samplable.h"
#include "DigitalInput.h"
#include "ListenerSubject.h"


//------------------------------------------------------------------------------------------------------------
//! The class SampledInput is responsible for hardware input representation.
//! It's the most updated view of the hardware input
//------------------------------------------------------------------------------------------------------------
class SimpleSampledInput: public Samplable,
					public DigitalInput{
public:
	//--------------------------------------------------------------------------------------------------------
	//! \pre "physicalInput" is the input we want to sample. GetState on this input should be possible
	//! immediately.
	//! \post None
	explicit SimpleSampledInput(DigitalInput & physicalInput);

	//--------------------------------------------------------------------------------------------------------
	//! \pre
	//! \post physical input reference IS NOT DELETED
	~SimpleSampledInput(){}

	//--------------------------------------------------------------------------------------------------------
	//! \pre  None
	//! \post update current state, reading low layer.
	//! Should be long return as we will ask the input to sample.
	virtual void Acquire();

	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post return official current state
	//! DO NOT READ LOW LAYER
	//! Really fast return as it's a simple accessor.
	virtual bool GetState() const;

private:
	DigitalInput & _inputToSample;
	//we store the "official" current state, instate interrogate each time needed _inputToSample.
	bool _officialCurrentState;
};


#endif /* SAMPLEDINPUT_H_ */
