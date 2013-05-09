#ifndef HARDWAREDIGITALINPUTEMULATOR_T_H_
#define HARDWAREDIGITALINPUTEMULATOR_T_H_

#include "../HardwareDigitalInputEmulator.h"

class HardwareDigitalInputEmulatorTest: public CxxTest::TestSuite
{
public:
	void testInstanciation()
	{
		bool sequence[] = {false,true,false,true};
		unsigned short sequenceSize = sizeof(sequence);
		HardwareDigitalInputEmulator emulatedInput(sequence,sequenceSize);
	}

	void testSequenceLatching()
	{
		bool sequence[] = {false,true,true};
		unsigned short sequenceSize = sizeof(sequence);
		HardwareDigitalInputEmulator emulatedInput(sequence,sequenceSize);
		TS_ASSERT(emulatedInput.GetState() == false);
		emulatedInput.latchNextState();
		TS_ASSERT(emulatedInput.GetState() == true);
		emulatedInput.latchNextState();
		TS_ASSERT(emulatedInput.GetState() == true);
		emulatedInput.latchNextState();
		TS_ASSERT(emulatedInput.GetState() == false);
	}
};


#endif /* HARDWAREDIGITALINPUTEMULATOR_T_H_ */
