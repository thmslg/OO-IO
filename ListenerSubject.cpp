#include "ListenerSubject.h"
#include "DelegateBooleanParameter.h" // to notify observers.

//--------------------------------------------------------------------------------------------------------
void ListenerSubject::subscribe(DelegateBooleanParameter * const delegateToInvoke)
{
	_observerList.push_back(delegateToInvoke);
}

//--------------------------------------------------------------------------------------------------------
void ListenerSubject::notifyListeners(bool newState)
{
	std::vector<DelegateBooleanParameter*>::iterator aListener =  _observerList.begin() ;
	for( aListener = _observerList.begin();
			aListener != _observerList.end();
			aListener++)
	{
		(*aListener)->Invoke(newState);
	}
}


