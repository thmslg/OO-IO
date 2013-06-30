#ifndef MPXV7002_H_
#define MPXV7002_H_

#include "PressureSensor.h"
#include "SingleEndedADCInput.h"

//--------------------------------------------------------------------------------------------------------
// This class is an abstraction of a fresscale sensor MPXV7002.
// Thanks to the datasheet we can extract this formula:
// Vout  = VS × (0.2 × P(kPa)+0.5) ± 6.25%VFSS.
// with VS = 5Vdc
// Further information on the internets/datasheet.
// As first test with decide to NOT TAKE INTO ACCOUNT the approx.
// So the following equation is used :
// VS = Vout / (0.2 × P(kPa)+0.5)
// i.e. P(Pa/10) = ((Vout/Vs)-0,5)/20
class MPXV7002 : public PressureSensor
{
public:
	//--------------------------------------------------------------------------------------------------------
	//! \pre "adc" will be used to read input value
	//! \post None
	MPXV7002( SingleEndedADCInput & adc);
	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post used ADC input IS NOT DELETED.
	virtual ~MPXV7002(){}

	//--------------------------------------------------------------------------------------------------------
	//! \pre See base class
	//! \post See base class
	virtual int GetPressureInTenthPa();
private:
	// An external ADC is reading the value on the physical sensor.
	SingleEndedADCInput & m_adc;
};

#endif /* MPXV7002_H_ */
