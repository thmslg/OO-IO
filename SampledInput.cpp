#include "SampledInput.h"

//--------------------------------------------------------------------------------------------------------
SampledInput::SampledInput(DigitalInput & physicalInput) :
		_inputToSample(physicalInput)
{
	_officialState = _inputToSample.GetState();
}

//--------------------------------------------------------------------------------------------------------
void SampledInput::Acquire()
{
	bool currentPhysicalState = _inputToSample.GetState();
	if(currentPhysicalState != _officialState)
	{
		_officialState = currentPhysicalState;
	}
}

//--------------------------------------------------------------------------------------------------------
bool SampledInput::GetState() const
{
	return _officialState;
}

