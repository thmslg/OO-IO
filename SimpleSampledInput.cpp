#include "SimpleSampledInput.h"

//--------------------------------------------------------------------------------------------------------
SimpleSampledInput::SimpleSampledInput(DigitalInput & physicalInput) :
		_inputToSample(physicalInput)
{
	_officialCurrentState = _inputToSample.GetState();
}

//--------------------------------------------------------------------------------------------------------
void SimpleSampledInput::Acquire()
{
	bool currentPhysicalState = _inputToSample.GetState();
	if(currentPhysicalState != _officialCurrentState)
	{
		_officialCurrentState = currentPhysicalState;
	}
}

//--------------------------------------------------------------------------------------------------------
bool SimpleSampledInput::GetState() const
{
	return _officialCurrentState;
}

