#ifndef SINGLEENDEDADCINPUT_T_H_
#define SINGLEENDEDADCINPUT_T_H_

#include "../SingleEndedADCInput.h"

class DummySingleEndedADCInput : public SingleEndedADCInput
{
public:
	DummySingleEndedADCInput(unsigned int fullScaleValue, float ReferenceVoltage) :
			SingleEndedADCInput(fullScaleValue,ReferenceVoltage)
	{

	}

	void UpdateInputValue(unsigned int newInputValue)
	{
		m_currentInputValue = newInputValue;
	}
};

class SinglEndedADCInputTest: public CxxTest::TestSuite
{
public:
	void testGetConvertedScaledInputValue()
	{
		//First test on 10 bit
		DummySingleEndedADCInput ADC(0xA,10);
		//We set the adc to a "half scale" input.
		ADC.UpdateInputValue(5);
		TS_ASSERT_EQUALS(ADC.GetConvertedScaledInputValue() , 5);
		TS_ASSERT_EQUALS(ADC.GetInputValue() , 5);
	}

	void testGetConvertedVoltage()
	{
		//First test on a "simple" example
		//ten steps of 1V
		DummySingleEndedADCInput ADC(0xA,10);
		TS_ASSERT_EQUALS(ADC.GetConvertedVoltage(1),1);
	}


	void testGetResolution()
	{
		//First test on a "simple" example
		DummySingleEndedADCInput ADC(0xA,10);
		TS_ASSERT_EQUALS(ADC.GetResolution(),1);
	}
};

#endif /* SINGLEENDEDADCINPUT_T_H_ */
