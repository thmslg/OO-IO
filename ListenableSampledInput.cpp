#include "ObservableSampledInput.h"
#include "ObserverSubject.h"
#include "DelegateBooleanParameter.h"


//--------------------------------------------------------------------------------------------------------
ListenableSampledInput::ListenableSampledInput(DigitalInput & inputToSample):
_inputToSample(inputToSample),
_currentOfficialState(_inputToSample.GetState())
{}

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
		//Notify
	}
}

//--------------------------------------------------------------------------------------------------------
void ListenableSampledInput::addListener(DelegateBooleanParameter & observerHandler)
{

}
