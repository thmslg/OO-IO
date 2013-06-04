#include "../ListenableSampledInput.h"
#include "../utils/ListenerSubject.h"
#include "../utils/DelegateBooleanParameter.h"


//--------------------------------------------------------------------------------------------------------
ListenableSampledInput::ListenableSampledInput(DigitalInput & inputToSample):
_inputToSample(inputToSample),
_currentOfficialState(_inputToSample.GetState()),
_notifier(new ListenerSubject())
{}

//--------------------------------------------------------------------------------------------------------
ListenableSampledInput::~ListenableSampledInput()
{
	delete _notifier;
}
//--------------------------------------------------------------------------------------------------------
bool ListenableSampledInput::GetState() const
{
	return _currentOfficialState;
}

//--------------------------------------------------------------------------------------------------------
void ListenableSampledInput::Acquire()
{
	if(_currentOfficialState != _inputToSample.GetState())
	{
		_currentOfficialState = _inputToSample.GetState();
		_notifier->notifyListeners(_currentOfficialState);
	}
}

//--------------------------------------------------------------------------------------------------------
void ListenableSampledInput::addListener(DelegateBooleanParameter * const observerHandler)
{
	_notifier->subscribe(observerHandler);
}
