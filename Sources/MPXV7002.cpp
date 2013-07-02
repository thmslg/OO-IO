#include "../MPXV7002.h"

//--------------------------------------------------------------------------------------------------------
MPXV7002::MPXV7002(SingleEndedADCInput & adc):
m_adc(adc)
{

}

//--------------------------------------------------------------------------------------------------------
int MPXV7002::GetPressureInTenthPa() const
{
	// P(Pa/10) = ((N/(2^k-1)-0,5) / 0,2)*10000
	if(_IsHighSaturated())
	{
		return 20000;
	}
	else if(_IsLowSaturated())
	{
		return -20000;
	}
	else
	{
		return (((float)m_adc.GetInputValue()/((float)m_adc.GetFullScaleValue()-1)) - ((float)0.5))/((float)0.2) * (float)10000 ;
	}

}

//--------------------------------------------------------------------------------------------------------
bool MPXV7002::IsSaturated() const
{
	return _IsHighSaturated() || _IsLowSaturated();
}

//--------------------------------------------------------------------------------------------------------
bool MPXV7002::_IsLowSaturated() const
{
	return (m_adc.GetConvertedScaledInputValue() < (float)0.5);
}

//--------------------------------------------------------------------------------------------------------
bool MPXV7002::_IsHighSaturated() const
{
	return (m_adc.GetConvertedScaledInputValue() > (float)4.5);
}
