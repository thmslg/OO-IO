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
	virtual int GetPressureInTenthPa() = 0;
};


#endif /* PRESSURESENSOR_H_ */
