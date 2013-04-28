#ifndef SAMPLEDINPUT_T_H_
#define SAMPLEDINPUT_T_H_

#include "../Input.h"
#include "../SampledInput.h"

#include "Mocks/DummyPhysicalInput.h"
#include "Mocks/DummyListener.h"

class SampledInputTest: public CxxTest::TestSuite
{
public:
	void testSimpleGetStateAtConstruction()
	{
		dummyPhysicalInput physicalInput(false);
		SampledInput sampledInput(physicalInput);
		TS_ASSERT(sampledInput.GetState() == false);

		dummyPhysicalInput physicalInput2(true);
		SampledInput sampledInput2(physicalInput2);
		TS_ASSERT(sampledInput2.GetState() == true);
	}

	void testSimpleAcquirement()
	{
		dummyPhysicalInput physicalInput(false);
		SampledInput sampledInput(physicalInput);

		physicalInput.changePhysicalState(true);
		TS_ASSERT(sampledInput.GetState() == false);
		sampledInput.Acquire();
		TS_ASSERT(sampledInput.GetState() == true);

		physicalInput.changePhysicalState(false);
		TS_ASSERT(sampledInput.GetState() == true);
		sampledInput.Acquire();
		TS_ASSERT(sampledInput.GetState() == false);
	}
	void testTestChangeNotify()
	{
		dummyPhysicalInput physicalInput(false);
		SampledInput sampledInput(physicalInput);
		DummyListener listener;
		TypedDelegate<DummyListener> * delegate = new TypedDelegate<DummyListener>(listener, &DummyListener::handler);
		sampledInput.subscribe(delegate);

		physicalInput.changePhysicalState(true);
		sampledInput.Acquire();
		TS_ASSERT(listener.handlerCalledSinceLastAsk() == true);
		TS_ASSERT(listener.lastParameterTransmitted() == true);

		physicalInput.changePhysicalState(false);
		sampledInput.Acquire();
		TS_ASSERT(listener.handlerCalledSinceLastAsk() == true);
		TS_ASSERT(listener.lastParameterTransmitted() == false);
	}
};

#endif /* SAMPLEDINPUT_T_H_ */
