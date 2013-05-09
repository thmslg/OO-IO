#include "InvertedListenableSampledInput.h"

//--------------------------------------------------------------------------------------------------------
InvertedListenableSampledInput::InvertedListenableSampledInput(ListenableSampledInput & inputToInvert) :
		_inputToInvert(inputToInvert),
		_delegateToInput(TypedDelegateBooleanParameter<InvertedListenableSampledInput>(*(this),
					&InvertedListenableSampledInput::InputToInvertHasChanged))
{
	_inputToInvert.addListener(&_delegateToInput);
}

//--------------------------------------------------------------------------------------------------------
void InvertedListenableSampledInput::InputToInvertHasChanged(bool newSTate)
{
	_notifier.notifyListeners(!newSTate);
}

//--------------------------------------------------------------------------------------------------------
void InvertedListenableSampledInput::addListener(DelegateBooleanParameter & listenerHandlerToAdd)
{
	_notifier.subscribe(&listenerHandlerToAdd);
}

//--------------------------------------------------------------------------------------------------------
bool InvertedListenableSampledInput::GetState() const
{
	// We could add an attribute in InvertedInput class as we don't know the
	// duration of this op'.
	return !_inputToInvert.GetState();
}
