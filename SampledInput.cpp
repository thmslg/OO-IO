#include "SampledInput.h"

//--------------------------------------------------------------------------------------------------------
SampledInput::SampledInput(DigitalInput & physicalInput) :
		_physicalInputToSample(physicalInput)
{
	_officialState = _physicalInputToSample.GetState();
}

//--------------------------------------------------------------------------------------------------------
void SampledInput::Acquire()
{
	bool currentPhysicalState = _physicalInputToSample.GetState();
	if(currentPhysicalState != _officialState)
	{
		_officialState = currentPhysicalState;
	}
}

//--------------------------------------------------------------------------------------------------------
bool SampledInput::GetState() const
{
//	bool logicLevel = false;
//
//	if (_isInverted)
//	{
//		logicLevel = !_physicalState;
//	}
//	else
//	{
//		logicLevel = _physicalState;
//	}
//
//	return logicLevel;
	return _officialState;
}

