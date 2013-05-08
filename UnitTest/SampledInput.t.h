#ifndef SAMPLEDINPUT_T_H_
#define SAMPLEDINPUT_T_H_

#include "../DigitalInput.h"
#include "../SampledInput.h"

#include "Mocks/DummyPhysicalInput.h"
#include "Mocks/DummyListener.h"

class SampledInputTest: public CxxTest::TestSuite
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

//	void testTestChangeNotify()
//	{
//		DummyPhysicalInput physicalInput(false);
//		SampledInput sampledInput(physicalInput);
//		DummyListener listener;
//		TypedDelegateBooleanParameter<DummyListener> * delegate = new TypedDelegateBooleanParameter<
//				DummyListener>(listener, &DummyListener::handler);
//		sampledInput.subscribe(delegate);
//
//		physicalInput.changePhysicalState(true);
//		sampledInput.Acquire();
//		TS_ASSERT(listener.handlerCalledSinceLastAsk() == true);
//		TS_ASSERT(listener.lastParameterTransmitted() == true);
//
//		physicalInput.changePhysicalState(false);
//		sampledInput.Acquire();
//		TS_ASSERT(listener.handlerCalledSinceLastAsk() == true);
//		TS_ASSERT(listener.lastParameterTransmitted() == false);
//	}
};

#endif /* SAMPLEDINPUT_T_H_ */
