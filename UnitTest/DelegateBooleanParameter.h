#include <cxxtest/TestSuite.h>

#include "../Delegate.h"

class DummyHandlerClass
{
public:
	DummyHandlerClass() :
	_lastParameter(false)
	{

	}
	void handler(bool dummyArgument)
	{
		_lastParameter = dummyArgument;
	}
	bool lastParameterTransmitted()
	{
		return _lastParameter;
	}
private:
	bool _lastParameter;
};

class MyTestSuite : public CxxTest::TestSuite
{
public:
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
