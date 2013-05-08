#ifndef DUMMYPHYSICALINPUT_H_
#define DUMMYPHYSICALINPUT_H_

#include "../ObserverSubject.h"
class DummyPhysicalInput: public DigitalInput, protected ObserverSubject
{
public:

	DummyPhysicalInput(bool state)
	{
		_physicalState = state;
	}
	virtual bool GetState() const
	{
		return _physicalState;
	}
	void changePhysicalState(bool newState)
	{
		if(_physicalState != newState)
		{
			_physicalState = newState;
			notifyObservers(_physicalState);
		}
	}
private:
	bool _physicalState;

};


#endif /* DUMMYPHYSICALINPUT_H_ */
