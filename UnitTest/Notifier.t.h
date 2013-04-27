#include "Delegate.h"
#include "Notifier.h"

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
		bool lastValue = _calledSinceLastAsk;
		_calledSinceLastAsk = false;
		return lastValue;

	}
private:
	bool _lastParameter;
	bool _calledSinceLastAsk;
};

class NotifierSuite : public CxxTest::TestSuite
{
public:
  void testParameterTransmission( void )
  {
//	  DummyHandlerClass handler;
//	  TypedDelegate<DummyHandlerClass> * delegate = new TypedDelegate<DummyHandlerClass>(handler,&DummyHandlerClass::handler);
//	  Notifier notifier;
//	  notifier.
  }
};
