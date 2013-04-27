#include "../Delegate.h"
#include "../Notifier.h"

class DummyHandlerClass
{
public:
	DummyHandlerClass() :
	_lastParameter(false),
	_calledSinceLastAsk(false)
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

class NotifierSuite : public CxxTest::TestSuite
{
public:
  void testNotify( void )
  {
	  DummyHandlerClass handler;
	  TypedDelegate<DummyHandlerClass> * delegate = new TypedDelegate<DummyHandlerClass>(handler,&DummyHandlerClass::handler);
	  Notifier notifier;
	  notifier.subscribe(delegate);
	  notifier.notify(true);
	  TS_ASSERT(handler.handlerCalledSinceLastAsk() == true);
	  notifier.notify(false);
	  TS_ASSERT(handler.handlerCalledSinceLastAsk() == true);

  }
  void testParameterTransmission( void )
  {
	  DummyHandlerClass handler;
	  TypedDelegate<DummyHandlerClass> * delegate = new TypedDelegate<DummyHandlerClass>(handler,&DummyHandlerClass::handler);
	  Notifier notifier;
	  notifier.subscribe(delegate);
	  notifier.notify(true);
	  TS_ASSERT(handler.lastParameterTransmitted() == true);
	  notifier.notify(false);
	  TS_ASSERT(handler.lastParameterTransmitted() == false);

  }
};
