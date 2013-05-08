#include "SimpleSampledInput.h"

//--------------------------------------------------------------------------------------------------------
SampledInput::SampledInput(DigitalInput & physicalInput) :
		_inputToSample(physicalInput)
{
	_officialCurrentState = _inputToSample.GetState();
}

//--------------------------------------------------------------------------------------------------------
void SampledInput::Acquire()
{
	bool currentPhysicalState = _inputToSample.GetState();
	if(currentPhysicalState != _officialCurrentState)
	{
		_officialCurrentState = currentPhysicalState;
	}
}

//--------------------------------------------------------------------------------------------------------
bool SampledInput::GetState() const
{
	return _officialCurrentState;
}

