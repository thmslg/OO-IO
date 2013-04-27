#include <cxxtest/TestSuite.h>

#include "../Delegate.h"


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

class DelegateTestSuite : public CxxTest::TestSuite
{
public:
	void testHandlerCall()
	{
		DummyHandlerClass handler;
		  TypedDelegate<DummyHandlerClass> * delegate = new TypedDelegate<DummyHandlerClass>(handler,&DummyHandlerClass::handler);
		  delegate->Invoke(true);
		  TS_ASSERT(handler.handlerCalledSinceLastAsk() == true);
		  TS_ASSERT(handler.handlerCalledSinceLastAsk() == false);
		  delegate->Invoke(false);
		  TS_ASSERT(handler.handlerCalledSinceLastAsk() == true);
		  TS_ASSERT(handler.handlerCalledSinceLastAsk() == false);
	}
  void testParameterTransmission( void )
  {
	  DummyHandlerClass handler;
	  TypedDelegate<DummyHandlerClass> * delegate = new TypedDelegate<DummyHandlerClass>(handler,&DummyHandlerClass::handler);
	  delegate->Invoke(true);
	  TS_ASSERT(handler.lastParameterTransmitted() == true);
	  delegate->Invoke(false);
	  TS_ASSERT(handler.lastParameterTransmitted() == false);
  }
};
