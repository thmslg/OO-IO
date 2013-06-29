#include "../SingleEndedADCInput.h"

//--------------------------------------------------------------------------------------------------------
float SingleEndedADCInput::GetConvertedScaledInputValue(unsigned int fullScaleVoltage)
{
	return ((float)m_currentInputValue / m_fullScaleValue)*fullScaleVoltage;
}

//--------------------------------------------------------------------------------------------------------
unsigned int SingleEndedADCInput::GetInputValue()
{
	return m_currentInputValue;
}
