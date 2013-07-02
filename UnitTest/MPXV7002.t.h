#ifndef MPXV7002_T_H_
#define MPXV7002_T_H_

#include "../MPXV7002.h"

class DummySingleEndedADCInput : public SingleEndedADCInput
{
public:
	DummySingleEndedADCInput(unsigned int fullScaleValue, float referenceVoltage) :
			SingleEndedADCInput(fullScaleValue,referenceVoltage)
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
	void testPressureSensorLaw()
	{
		//We plan to use a 17bit full scale ADC.
		DummySingleEndedADCInput ADC(0x1FFFF,5);
		MPXV7002 sensor(ADC);
		//We test three "characteristic" points of the datasheet graph.
		//We DO NOT consider the approximation.
		// O,5V
		ADC.UpdateInputValue((0x1FFFF/10)-1);
		TS_ASSERT_EQUALS(sensor.GetPressureInTenthPa(), -20000);
		// 2,5V
		ADC.UpdateInputValue(0x1FFFF/2);
		TS_ASSERT_EQUALS(sensor.GetPressureInTenthPa(), 0);
		// 4,5V
		ADC.UpdateInputValue(9*(0x1FFFF/10)+1);
		TS_ASSERT_EQUALS(sensor.GetPressureInTenthPa(), 20000);
	}

};



#endif /* MPXV7002_T_H_ */
