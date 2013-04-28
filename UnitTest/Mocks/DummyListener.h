#ifndef DUMMYLISTENER_H_
#define DUMMYLISTENER_H_



class DummyListener
{
public:
	DummyListener() :
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

#endif /* DUMMYLISTENER_H_ */
