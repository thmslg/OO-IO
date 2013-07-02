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
//
// My choices :
// As first test with decide to NOT TAKE INTO ACCOUNT the approx.
// So the following equation is used :
// VS = Vout / (0.2 × P(kPa)+0.5)
// i.e. P(Pa/10) = ((N/(2^k-1)-0,5) / 0,2)*10000
// This equation is ranged. We have a saturated state before 0,5V and after 4,5V.
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
	virtual int GetPressureInTenthPa() const;

	//--------------------------------------------------------------------------------------------------------
	//! \pre See base class
	//! \post See base class
	virtual bool IsSaturated() const;
private:
	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post return true if the sensor is saturated on the low voltage side, I.E < 0,5V
	bool _IsLowSaturated() const;

	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post return true if the sensor is saturated on the high voltage side, I.E < 4,5V
	bool _IsHighSaturated() const;

	// An external ADC is reading the value on the physical sensor.
	SingleEndedADCInput & m_adc;
};

#endif /* MPXV7002_H_ */
