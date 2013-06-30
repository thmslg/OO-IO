#ifndef MPXV7002_T_H_
#define MPXV7002_T_H_

#include "../MPXV7002.h"

class DummySingleEndedADCInput : public SingleEndedADCInput
{
public:
	DummySingleEndedADCInput(unsigned int fullScaleValue) :
			SingleEndedADCInput(fullScaleValue)
	{

	}

	void UpdateInputValue(unsigned int newInputValue)
	{
		m_currentInputValue = newInputValue;
	}
};

class MPXV7002Test: public CxxTest::TestSuite
{
public:
	void testSimpleGetStateAtConstruction()
	{
		//We plan to use a 17bit full scale.
		DummySingleEndedADCInput ADC(0x1FFFF);
		MPXV7002 sensor(ADC);
		// O,5V
		ADC.UpdateInputValue(0x1FFFF/10);
		TS_ASSERT_EQUALS(sensor.GetPressureInTenthPa(), -20000);
		// 2,5V
		ADC.UpdateInputValue(0x1FFFF/2);
		TS_ASSERT_EQUALS(sensor.GetPressureInTenthPa(), 0);
		// 4,5V
		ADC.UpdateInputValue(9*(0x1FFFF/10));
		TS_ASSERT_EQUALS(sensor.GetPressureInTenthPa(), 20000);
	}

};



#endif /* MPXV7002_T_H_ */
