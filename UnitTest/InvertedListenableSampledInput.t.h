#ifndef INPUTINVERT_T_H_
#define INPUTINVERT_T_H_

#include "../InvertedListenableSampledInput.h"
#include "../ListenableSampledInput.h"

#include "Mocks/DummyPhysicalInput.h"
#include "Mocks/DummyListener.h"

class InvertedInputTest: public CxxTest::TestSuite
{
public:
	void testInstanciation(void)
	{
		DummyPhysicalInput physicalInput(false);
		ListenableSampledInput inputToInvert(physicalInput);
		InvertedListenableSampledInput invertedInput(inputToInvert);
		TS_ASSERT(invertedInput.GetState() == true);

		DummyPhysicalInput physicalInput2(true);
		ListenableSampledInput inputToInvert2(physicalInput2);
		InvertedListenableSampledInput invertedInput2(inputToInvert2);
		TS_ASSERT(invertedInput2.GetState() == false);
	}

	void testInvertedNotify()
	{

		DummyListener listener;
		TypedDelegateBooleanParameter<DummyListener> delegate(listener, &DummyListener::handler);

		DummyPhysicalInput physicalInput(false);
		ListenableSampledInput sampledInput(physicalInput);
		InvertedListenableSampledInput invertedInput(sampledInput);
		invertedInput.addListener(delegate);
		physicalInput.changePhysicalState(true);
		sampledInput.Acquire();

		TS_ASSERT(listener.handlerCalledSinceLastAsk() == true);
		TS_ASSERT(listener.lastParameterTransmitted() == false);

		physicalInput.changePhysicalState(false);
		sampledInput.Acquire();
		TS_ASSERT(listener.handlerCalledSinceLastAsk() == true);
		TS_ASSERT(listener.lastParameterTransmitted() == true);
	}

};

#endif /* INPUTINVERT_T_H_ */
