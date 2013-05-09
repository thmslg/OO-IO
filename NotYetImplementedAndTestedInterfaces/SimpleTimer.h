#ifndef SIMPLETIMER_H_
#define SIMPLETIMER_H_

// Forward declaration ! User will include Delegate.
#include "Delegate.h"

class SimpleTimer
{

public:
	//------------------------------------------------------------------------------------------------------------
	//! \pre
	//! \post
	explicit SimpleTimer()
	{
	}

	virtual ~SimpleTimer()
	{
	}
	//------------------------------------------------------------------------------------------------------------
	//! \pre timeoutDelay in ms
	//! 	Should not be already armed ! Ask "IsArmed" to know !
	//! \post FilterTimer armed ! handlerWhenTimerElapsed will be call in timeoutDelayInMs !
	//! 		Assert will be launched if already armed before !!
	virtual void arm(int timeoutDelayInMs, DelegateBooleanParameter *handlerWhenTimerElapsed, bool NewStateToTransmit) = 0;

	//------------------------------------------------------------------------------------------------------------
	//! \pre none
	//! \post return true if arm timer is currently armed.
	virtual bool isAlreadyArmed() = 0;

	//------------------------------------------------------------------------------------------------------------
	//! \pre
	//! \post disarm timer.
	// 		return true if timer was already armed
	//		return false if timer was NOT armed
	virtual bool disarm() = 0;
};



#endif /* SIMPLETIMER_H_ */
