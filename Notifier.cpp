#include "Notifier.h"

//--------------------------------------------------------------------------------------------------------
void Notifier::subscribe(DelegateBooleanParameter * const delegateToInvoke)
{
	_delegateContainer.push_back(delegateToInvoke);
}

//--------------------------------------------------------------------------------------------------------
void Notifier::notifyListeners(bool newState)
{
	std::vector<DelegateBooleanParameter*>::iterator aListener =  _delegateContainer.begin() ;
	for( aListener = _delegateContainer.begin();
			aListener != _delegateContainer.end();
			aListener++)
	{
		(*aListener)->Invoke(newState);
	}
}


