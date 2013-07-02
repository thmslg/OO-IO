#ifndef PRESSURESENSOR_H_
#define PRESSURESENSOR_H_

class PressureSensor
{
public:
	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post None
	virtual ~PressureSensor(){}
	//--------------------------------------------------------------------------------------------------------
	//! \pre "None"
	//! \post Return the current pressure in Pa/10
	virtual int GetPressureInTenthPa() const = 0 ;
	//--------------------------------------------------------------------------------------------------------
	//! \pre "None"
	//! \post A sensor output voltage is only reliable in a voltage range.
	//	If the sensor is NOT IN THIS RANGE, we consider it "saturated".
	//	So the value is not a "real" one.
	virtual bool IsSaturated() const = 0;
};


#endif /* PRESSURESENSOR_H_ */
