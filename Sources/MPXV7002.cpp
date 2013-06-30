#include "../MPXV7002.h"

//--------------------------------------------------------------------------------------------------------
MPXV7002::MPXV7002(SingleEndedADCInput & adc):
m_adc(adc)
{

}

//--------------------------------------------------------------------------------------------------------
int MPXV7002::GetPressureInTenthPa()
{
	// P(Pa/10) = (N/(2^k-1))-0,5) / 2000
	// float pouet = (float)m_adc.GetInputValue();
	// float pouet2 = (float)m_adc.GetFullScaleValue();
	// float pouet3 = ((float)m_adc.GetInputValue()/((float)m_adc.GetFullScaleValue()-1));
	// float pouet4 = ((float)m_adc.GetInputValue()/((float)m_adc.GetFullScaleValue()-1)) - ((float)0.5);
	// float pouet5 = (((float)m_adc.GetInputValue()/((float)m_adc.GetFullScaleValue()-1)) - ((float)0.5))/((float)0.2);

	return (((float)m_adc.GetInputValue()/((float)m_adc.GetFullScaleValue()-1)) - ((float)0.5))/((float)0.2) * (float)10000 ;
}

