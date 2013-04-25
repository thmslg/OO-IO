#include "SampledInput.h"

SampledInput::SampledInput(bool isInverted):
Samplable(),
_physicalState(isInverted),
_isInverted(isInverted)
{
}

SampledInput::~SampledInput(){

}


//--------------------------------------------------------------------------------------------------------
void SampledInput::Acquire()
{
	bool newState = GetState();
	if(newState != _physicalState)
	{
		if(_isInverted)
		{
			notify(!newState);
		}
		else
		{
			notify(newState);
		}
		_physicalState = newState;
	}
}

//--------------------------------------------------------------------------------------------------------
bool SampledInput::GetState() const
{
	bool logicLevel = false;

	if( _isInverted)
	{
		logicLevel = !_physicalState;
	}
	else
	{
		logicLevel = _physicalState;
	}

	return logicLevel;
}

//--------------------------------------------------------------------------------------------------------
void SampledInput::ChangeInversion(bool inversion)
{
	_isInverted = inversion;
	//We force the physical state in order to generate the event.
	_physicalState = _isInverted;
	Acquire();
}



