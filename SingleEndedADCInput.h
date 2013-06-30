#ifndef SINGLEENDEDADCINPUT_H_
#define SINGLEENDEDADCINPUT_H_

//--------------------------------------------------------------------------------------------------------
//! An Analogue to Digital Converter could generaly be set in different mode. SingleEnded (AX -> Gnd) or
//! differential mode (AX -> AY). This abstraction manage the SingleEnded case.
//! WARNING : currently this class manage 17bits converter ! Should be generalized after.
class SingleEndedADCInput
{
public:
	//--------------------------------------------------------------------------------------------------------
	//! \pre "fullScaleValue" value of full scale (for example ADC 17bits : 0x1FFFF)
	//! \post
	SingleEndedADCInput(unsigned int fullScaleValue) :
	m_fullScaleValue(fullScaleValue),
	m_currentInputValue(0)
	{}
	//--------------------------------------------------------------------------------------------------------
	virtual ~SingleEndedADCInput()
	{}

	//-------- QUERIES ---------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post Return the last acquired input value.
	//! return value SHOULD NOT be higher than fullScaleValue :
	unsigned int GetInputValue();

	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post Return the fullScaleValue for external computation.
	unsigned int GetFullScaleValue()
	{
		return m_fullScaleValue;
	}
	//--------------------------------------------------------------------------------------------------------
	//! \pre "fullScaleVoltage" voltage applied to the ADC, corresponding to the full scale value
	//! \post return the converted last acquired input voltage.
	//! WARNING : float division, long operation
	float GetConvertedScaledInputValue(unsigned int fullScaleVoltage);

protected:
	//--------------------------------------------------------------------------------------------------------
	unsigned int const m_fullScaleValue;
	//--------------------------------------------------------------------------------------------------------
	unsigned int m_currentInputValue;

};

#endif /* SINGLEENDEDADCINPUT_H_ */
