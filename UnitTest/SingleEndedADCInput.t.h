#ifndef SINGLEENDEDADCINPUT_T_H_
#define SINGLEENDEDADCINPUT_T_H_

#include "../SingleEndedADCInput.h"

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

class SinglEndedADCInputTest: public CxxTest::TestSuite
{
public:
	void testSimpleGetStateAtConstruction()
	{
		//First test on 10 bit
		DummySingleEndedADCInput ADC(0xA);
		ADC.UpdateInputValue(5);
		unsigned int const fullScaleInputVoltage = 10;
		TS_ASSERT_EQUALS(ADC.GetConvertedScaledInputValue(fullScaleInputVoltage) , 5);
		TS_ASSERT_EQUALS(ADC.GetInputValue() , 5);
	}

};

#endif /* SINGLEENDEDADCINPUT_T_H_ */
