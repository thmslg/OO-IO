#ifndef INPUT_H_
#define INPUT_H_
#include "Notifier.h"

class Input : public Notifier
{
public:

	explicit Input():
	Notifier()
	{
	}

	virtual ~Input(){}
	virtual bool GetState() const = 0;
	virtual void ChangeInversion(bool value) =0;
};


#endif /* INPUT_H_ */
