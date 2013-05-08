#ifndef SIMPLESAMPLEDINPUT_T_H
#define SIMPLESAMPLEDINPUT_T_H

#include "../DigitalInput.h"
#include "../SimpleSampledInput.h"

#include "Mocks/DummyPhysicalInput.h"
#include "Mocks/DummyListener.h"

class SimpleSampledInputTest: public CxxTest::TestSuite
{
public:
	void testSimpleGetStateAtConstruction()
	{
		DummyPhysicalInput physicalInput(false);
		SampledInput sampledInput(physicalInput);
		TS_ASSERT(sampledInput.GetState() == false);

		DummyPhysicalInput physicalInput2(true);
		SampledInput sampledInput2(physicalInput2);
		TS_ASSERT(sampledInput2.GetState() == true);
	}

	void testSimpleAcquirement()
	{
		DummyPhysicalInput physicalInput(false);
		SampledInput sampledInput(physicalInput);

		//Low to high
		physicalInput.changePhysicalState(true);
		TS_ASSERT(sampledInput.GetState() == false);
		sampledInput.Acquire();
		TS_ASSERT(sampledInput.GetState() == true);

		//high to low
		physicalInput.changePhysicalState(false);
		TS_ASSERT(sampledInput.GetState() == true);
		sampledInput.Acquire();
		TS_ASSERT(sampledInput.GetState() == false);
	}
};

#endif /* SIMPLESAMPLEDINPUT_T_H */
