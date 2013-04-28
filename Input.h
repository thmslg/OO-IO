#ifndef INPUT_H_
#define INPUT_H_
#include "Notifier.h"

//--------------------------------------------------------------------------------------------------------
// This class is responsible for encapsulate an Input behavior.
// You can obtain the current official state of the input and be notified when the state of the input
// change.
class Input : public Notifier
{
public:

	explicit Input()
	{
	}

	virtual ~Input(){}

	//--------------------------------------------------------------------------------------------------------
	//! \pre
	//! \post Get the current official state of the input.
	//! Should be different of the electric one, return only the official one.
	//! (For example in case of filtered input)
	virtual bool GetState() const = 0;
};


#endif /* INPUT_H_ */
