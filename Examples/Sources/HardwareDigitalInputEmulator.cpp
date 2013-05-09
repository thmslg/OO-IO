#include "../HardwareDigitalInputEmulator.h"

//--------------------------------------------------------------------------------------------------------
void HardwareDigitalInputEmulator::latchNextState()
{
	//we are in the sequence
	if(_sequenceIndex+1 < _sequenceSize)
	{
		_sequenceIndex++;
	}
	else
	{
		//we are at the end of the sequence, retsart to the beginning
		_sequenceIndex = 0;
	}
}

//--------------------------------------------------------------------------------------------------------
bool HardwareDigitalInputEmulator::GetState() const
{
	return _sequence[_sequenceIndex];
}
