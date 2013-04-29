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
	notifyListeners(!newSTate);
}
bool InvertedInput::GetState() const
{
	// We could add an attribute in InvertedInput class as we don't know the
	// duration of this op'.
	return !_inputToInvert.GetState();
}
