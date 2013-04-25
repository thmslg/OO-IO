#include "Notifier.h"


Notifier::Notifier():
_delegateContainerSize(maxNumberOfDelegates),
_delegateContainerIndex(0)
{
}

Notifier::~Notifier()
{
}

//--------------------------------------------------------------------------------------------------------
bool Notifier::subscribe(Delegate * const delegateToInvoke)
{
	bool IsSubscribed = false;

    //! \todo replace this test by an assertion
	if (_delegateContainerIndex < _delegateContainerSize)
	{
		_delegateContainer[_delegateContainerIndex] = delegateToInvoke;
		_delegateContainerIndex++;
		IsSubscribed = true;
	}
	return IsSubscribed;
}

//--------------------------------------------------------------------------------------------------------
void Notifier::notify(bool newState)
{

		for(int index=0; index<_delegateContainerIndex;index++)
		{
			_delegateContainer[index]->Invoke(newState);
		}
}


