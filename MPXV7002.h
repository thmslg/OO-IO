#ifndef MPXV7002_H_
#define MPXV7002_H_

#include "PressureSensor.h"
#include "SingleEndedADCInput.h"

//--------------------------------------------------------------------------------------------------------
// This class is an abstraction of a fresscale sensor MPXV7002.
// Further information on the internet.
class MPXV7002 : public PressureSensor
{
public:
	//--------------------------------------------------------------------------------------------------------
	//! \pre "adc" will be use to read input value
	//! \post None
	MPXV7002( SingleEndedADCInput & adc);
	virtual ~MPXV7002();
private:
	// An external ADC is reading the value on the physical sensor.
	SingleEndedADCInput & m_adc;
};

#endif /* MPXV7002_H_ */
