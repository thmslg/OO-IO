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
	SingleEndedADCInput(unsigned int fullScaleValue,
						float fullScalleVoltage) :
	m_fullScaleValue(fullScaleValue),
	m_currentInputValue(0),
	m_fullScaleVoltage(fullScalleVoltage)
	{}
	//--------------------------------------------------------------------------------------------------------
	virtual ~SingleEndedADCInput()
	{}

	//-------- QUERIES ---------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post Return the last acquired input value.
	//! return value SHOULD NOT be higher than fullScaleValue :
	unsigned int GetInputValue() const
	{
		return m_currentInputValue;
	}

	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post Return the fullScaleValue for external computation.
	unsigned int GetFullScaleValue() const
	{
		return m_fullScaleValue;
	}

	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post return the converted last acquired input voltage, in Volt.
	//! WARNING : float division, long operation
	float GetConvertedScaledInputValue() const;

	//--------------------------------------------------------------------------------------------------------
	//! \pre "voltage" value asked
	//! \post corresponding input value
	//! WARNING it's not EXACTLY the same value, we have a defined resolution.
	//! SEE GetResolution() to know the maximum difference
	unsigned int GetConvertedVoltage(float voltage) const;

	//--------------------------------------------------------------------------------------------------------
	//! \pre "None"
	//! \post Return the resolution of the ADC.
	//! Measured voltage is approx. +- resolution.
	float GetResolution() const;

protected:
	//--------------------------------------------------------------------------------------------------------
	unsigned int const m_fullScaleValue;
	//--------------------------------------------------------------------------------------------------------
	unsigned int m_currentInputValue;
	//--------------------------------------------------------------------------------------------------------
	float m_fullScaleVoltage;

};

#endif /* SINGLEENDEDADCINPUT_H_ */
