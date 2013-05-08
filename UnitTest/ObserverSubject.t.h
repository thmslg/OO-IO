#include "../DelegateBooleanParameter.h"
#include "../ObserverSubject.h"
#include "Mocks/DummyListener.h"

class NotifierSuite: public CxxTest::TestSuite
{
public:
	void testListener(void)
	{
		DummyListener dummyListener;
		TypedDelegateBooleanParameter<DummyListener> * delegate = new TypedDelegateBooleanParameter<
				DummyListener>(dummyListener, &DummyListener::handler);
		ObserverSubject notifier;
		notifier.subscribe(delegate);
		notifier.notifyObserver(true);
		TS_ASSERT(dummyListener.handlerCalledSinceLastAsk() == true);
		notifier.notifyObserver(false);
		TS_ASSERT(dummyListener.handlerCalledSinceLastAsk() == true);

	}

	void testParameterTransmission(void)
	{
		DummyListener dummyListener;
		TypedDelegateBooleanParameter<DummyListener> * delegate = new TypedDelegateBooleanParameter<
				DummyListener>(dummyListener, &DummyListener::handler);
		ObserverSubject notifier;
		notifier.subscribe(delegate);
		notifier.notifyObserver(true);
		TS_ASSERT(dummyListener.lastParameterTransmitted() == true);
		notifier.notifyObserver(false);
		TS_ASSERT(dummyListener.lastParameterTransmitted() == false);

	}

	void testMultipleListeners(void)
	{
		DummyListener dummyListenerA;
		TypedDelegateBooleanParameter<DummyListener> * delegateA = new TypedDelegateBooleanParameter<
				DummyListener>(dummyListenerA, &DummyListener::handler);

		DummyListener dummyListenerB;
		TypedDelegateBooleanParameter<DummyListener> * delegateB = new TypedDelegateBooleanParameter<
				DummyListener>(dummyListenerB, &DummyListener::handler);
		ObserverSubject notifier;
		notifier.subscribe(delegateA);
		notifier.subscribe(delegateB);

		notifier.notifyObserver(true);
		TS_ASSERT(dummyListenerA.handlerCalledSinceLastAsk() == true);
		TS_ASSERT(dummyListenerB.handlerCalledSinceLastAsk() == true);

		notifier.notifyObserver(false);
		TS_ASSERT(dummyListenerA.handlerCalledSinceLastAsk() == true);
		TS_ASSERT(dummyListenerB.handlerCalledSinceLastAsk() == true);

	}

	void testMultipleListenersParameterTransmission(void)
	{
		DummyListener dummyListenerA;
		TypedDelegateBooleanParameter<DummyListener> * delegateA = new TypedDelegateBooleanParameter<
				DummyListener>(dummyListenerA, &DummyListener::handler);

		DummyListener dummyListenerB;
		TypedDelegateBooleanParameter<DummyListener> * delegateB = new TypedDelegateBooleanParameter<
				DummyListener>(dummyListenerB, &DummyListener::handler);
		ObserverSubject notifier;
		notifier.subscribe(delegateA);
		notifier.subscribe(delegateB);

		notifier.notifyObserver(true);
		TS_ASSERT(dummyListenerA.lastParameterTransmitted() == true);
		TS_ASSERT(dummyListenerB.lastParameterTransmitted() == true);

		notifier.notifyObserver(false);
		TS_ASSERT(dummyListenerA.lastParameterTransmitted() == false);
		TS_ASSERT(dummyListenerB.lastParameterTransmitted() == false);

	}
};
