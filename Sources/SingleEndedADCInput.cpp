#include "../SingleEndedADCInput.h"

//--------------------------------------------------------------------------------------------------------
float SingleEndedADCInput::GetConvertedScaledInputValue() const
{
	return ((float)m_currentInputValue / m_fullScaleValue) * m_fullScaleVoltage;
}

//--------------------------------------------------------------------------------------------------------
unsigned int SingleEndedADCInput::GetConvertedVoltage(float expectedVoltage) const
{
	return expectedVoltage*(float)m_fullScaleValue/m_fullScaleVoltage;
}

float SingleEndedADCInput::GetResolution() const
{
	return m_fullScaleVoltage/(float)m_fullScaleValue;
}
