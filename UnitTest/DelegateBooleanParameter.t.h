#include <cxxtest/TestSuite.h>

#include "../DelegateBooleanParameter.h"
#include "Mocks/DummyListener.h"

class DelegateTestSuite: public CxxTest::TestSuite
{
public:
	void testHandlerCall()
	{
		DummyListener handler;
		TypedDelegateBooleanParameter<DummyListener> * delegate = new TypedDelegateBooleanParameter<
				DummyListener>(handler, &DummyListener::handler);
		delegate->Invoke(true);
		TS_ASSERT(handler.handlerCalledSinceLastAsk() == true);
		TS_ASSERT(handler.handlerCalledSinceLastAsk() == false);
		delegate->Invoke(false);
		TS_ASSERT(handler.handlerCalledSinceLastAsk() == true);
		TS_ASSERT(handler.handlerCalledSinceLastAsk() == false);
	}
	void testParameterTransmission(void)
	{
		DummyListener handler;
		TypedDelegateBooleanParameter<DummyListener> * delegate = new TypedDelegateBooleanParameter<
				DummyListener>(handler, &DummyListener::handler);
		delegate->Invoke(true);
		TS_ASSERT(handler.lastParameterTransmitted() == true);
		delegate->Invoke(false);
		TS_ASSERT(handler.lastParameterTransmitted() == false);
	}
};
