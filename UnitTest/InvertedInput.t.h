#ifndef INPUTINVERT_T_H_
#define INPUTINVERT_T_H_

#include "../InvertedInput.h"
#include "Mocks/DummyPhysicalInput.h"
#include "Mocks/DummyListener.h"

class InvertedInputTest: public CxxTest::TestSuite
{
public:
	void testInstanciation(void)
	{
		DummyPhysicalInput physicalInput(false);
		InvertedInput invertedInput(physicalInput);
		TS_ASSERT(invertedInput.GetState() == true);

		DummyPhysicalInput physicalInput2(true);
		InvertedInput invertedInput2(physicalInput2);
		TS_ASSERT(invertedInput2.GetState() == false);
	}

	void testTestChangeNotify()
	{
		DummyPhysicalInput physicalInput(false);
		DummyListener listener;
		TypedDelegate<DummyListener> * delegate = new TypedDelegate<
				DummyListener>(listener, &DummyListener::handler);
		InvertedInput invertedInput(physicalInput);
		invertedInput.subscribe(delegate);
		physicalInput.changePhysicalState(true);
		TS_ASSERT(listener.handlerCalledSinceLastAsk() == true);
		TS_ASSERT(listener.lastParameterTransmitted() == false);

		physicalInput.changePhysicalState(false);
		TS_ASSERT(listener.handlerCalledSinceLastAsk() == true);
		TS_ASSERT(listener.lastParameterTransmitted() == true);
	}

};

#endif /* INPUTINVERT_T_H_ */
