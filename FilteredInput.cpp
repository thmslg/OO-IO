#include "FilteredInput.h"

#include <stddef.h> // for NULL pointer
#include "SimpleTimer.h"

//------------------------------------------------------------------------------------------------------------
FilteredInput::FilteredInput(Input & inputToFilter,
							int filteringTime,
							bool filteredActiveState,
							SimpleTimer & timer):
_inputToFilter(inputToFilter),
_simpleTimer(timer),
_inputDelegate(*this,&FilteredInput::inputHasChanged),
_filteredState(inputToFilter.GetState()),
_filteringTime(filteringTime),
_ActiveState(filteredActiveState),
_simpleTimerDelegate(*(this), &FilteredInput::timerElapsed)
{
	_inputToFilter.subscribe(&_inputDelegate);
}

//------------------------------------------------------------------------------------------------------------
FilteredInput::~FilteredInput() {
}

//------------------------------------------------------------------------------------------------------------
bool FilteredInput::GetState() const
{
	return _filteredState;
}

//------------------------------------------------------------------------------------------------------------
void FilteredInput::inputHasChanged(bool newState)
{
	if(newState == _ActiveState)
	{
		//Active edge detected !!
		_simpleTimer.arm(_filteringTime,&_simpleTimerDelegate,newState);
	}
	else
	{
		_simpleTimer.disarm() ;
		if(newState != _filteredState)
		{
			notify(newState);
			_filteredState = newState; // see GetState
		}
	}
}

//------------------------------------------------------------------------------------------------------------
void FilteredInput::timerElapsed(bool newState){
	_filteredState = newState;
	notify(newState);
}

//------------------------------------------------------------------------------------------------------------
void FilteredInput::ChangeInversion(bool inversion)
{
	_inputToFilter.ChangeInversion(inversion);

}
