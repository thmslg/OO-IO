#include "InvertedInput.h"

InvertedInput::InvertedInput(Input & inputToInvert) :
		_inputToInvert(inputToInvert),
		_delegateToInput(TypedDelegate<InvertedInput>(*(this),
					&InvertedInput::InputToInvertHasChanged))
{
	_inputToInvert.subscribe(&_delegateToInput);
}
void InvertedInput::InputToInvertHasChanged(bool newSTate)
{
	notify(!newSTate);
}
bool InvertedInput::GetState() const
{
	return !_inputToInvert.GetState();
}
