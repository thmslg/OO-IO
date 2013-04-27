#include "../Delegate.h"
#include "../Notifier.h"

class DummyListener
{
public:
	DummyListener() :
			_lastParameter(false), _calledSinceLastAsk(false)
	{

	}
	void handler(bool dummyArgument)
	{
		_lastParameter = dummyArgument;
		_calledSinceLastAsk = true;
	}
	bool lastParameterTransmitted()
	{
		return _lastParameter;
	}
	bool handlerCalledSinceLastAsk()
	{
		bool wasCalledBefore = _calledSinceLastAsk;
		_calledSinceLastAsk = false;
		return wasCalledBefore;

	}
private:
	bool _lastParameter;
	bool _calledSinceLastAsk;
};

class NotifierSuite: public CxxTest::TestSuite
{
public:
	void testListener(void)
	{
		DummyListener dummyListener;
		TypedDelegate<DummyListener> * delegate = new TypedDelegate<
				DummyListener>(dummyListener, &DummyListener::handler);
		Notifier notifier;
		notifier.subscribe(delegate);
		notifier.notify(true);
		TS_ASSERT(dummyListener.handlerCalledSinceLastAsk() == true);
		notifier.notify(false);
		TS_ASSERT(dummyListener.handlerCalledSinceLastAsk() == true);

	}

	void testParameterTransmission(void)
	{
		DummyListener dummyListener;
		TypedDelegate<DummyListener> * delegate = new TypedDelegate<
				DummyListener>(dummyListener, &DummyListener::handler);
		Notifier notifier;
		notifier.subscribe(delegate);
		notifier.notify(true);
		TS_ASSERT(dummyListener.lastParameterTransmitted() == true);
		notifier.notify(false);
		TS_ASSERT(dummyListener.lastParameterTransmitted() == false);

	}

	void testMultipleListeners(void)
	{
		DummyListener dummyListenerA;
		TypedDelegate<DummyListener> * delegateA = new TypedDelegate<
				DummyListener>(dummyListenerA, &DummyListener::handler);

		DummyListener dummyListenerB;
		TypedDelegate<DummyListener> * delegateB = new TypedDelegate<
				DummyListener>(dummyListenerB, &DummyListener::handler);
		Notifier notifier;
		notifier.subscribe(delegateA);
		notifier.subscribe(delegateB);

		notifier.notify(true);
		TS_ASSERT(dummyListenerA.handlerCalledSinceLastAsk() == true);
		TS_ASSERT(dummyListenerB.handlerCalledSinceLastAsk() == true);

		notifier.notify(false);
		TS_ASSERT(dummyListenerA.handlerCalledSinceLastAsk() == true);
		TS_ASSERT(dummyListenerB.handlerCalledSinceLastAsk() == true);

	}

	void testMultipleListenersParameterTransmission(void)
	{
		DummyListener dummyListenerA;
		TypedDelegate<DummyListener> * delegateA = new TypedDelegate<
				DummyListener>(dummyListenerA, &DummyListener::handler);

		DummyListener dummyListenerB;
		TypedDelegate<DummyListener> * delegateB = new TypedDelegate<
				DummyListener>(dummyListenerB, &DummyListener::handler);
		Notifier notifier;
		notifier.subscribe(delegateA);
		notifier.subscribe(delegateB);

		notifier.notify(true);
		TS_ASSERT(dummyListenerA.lastParameterTransmitted() == true);
		TS_ASSERT(dummyListenerB.lastParameterTransmitted() == true);

		notifier.notify(false);
		TS_ASSERT(dummyListenerA.lastParameterTransmitted() == false);
		TS_ASSERT(dummyListenerB.lastParameterTransmitted() == false);

	}
};
