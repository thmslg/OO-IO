#include "Notifier.h"

//--------------------------------------------------------------------------------------------------------
void Notifier::subscribe(Delegate * const delegateToInvoke)
{
	_delegateContainer.push_back(delegateToInvoke);
}

//--------------------------------------------------------------------------------------------------------
void Notifier::notify(bool newState)
{
	std::vector<Delegate*>::iterator aListener =  _delegateContainer.begin() ;
	for( aListener = _delegateContainer.begin();
			aListener != _delegateContainer.end();
			aListener++)
	{
		(*aListener)->Invoke(newState);
	}
}


