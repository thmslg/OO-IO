#include "../MPXV7002.h"

//--------------------------------------------------------------------------------------------------------
MPXV7002::MPXV7002(SingleEndedADCInput & adc):
m_adc(adc)
{

}

//--------------------------------------------------------------------------------------------------------
int MPXV7002::GetPressureInTenthPa()
{
	return 0;
}

