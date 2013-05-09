#include "../ListenerSubject.h"
#include "../DelegateBooleanParameter.h" // to notify observers.

//--------------------------------------------------------------------------------------------------------
void ListenerSubject::subscribe(DelegateBooleanParameter * const delegateToInvoke)
{
	_listenerList.push_back(delegateToInvoke);
}

//--------------------------------------------------------------------------------------------------------
void ListenerSubject::notifyListeners(bool newState)
{
	std::vector<DelegateBooleanParameter*>::iterator aListener =  _listenerList.begin() ;
	for( aListener = _listenerList.begin();
			aListener != _listenerList.end();
			aListener++)
	{
		(*aListener)->Invoke(newState);
	}
}


