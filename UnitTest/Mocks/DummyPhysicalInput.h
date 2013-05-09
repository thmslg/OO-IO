#ifndef DUMMYPHYSICALINPUT_H_
#define DUMMYPHYSICALINPUT_H

class DummyPhysicalInput: public DigitalInput
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
		}
	}
private:
	bool _physicalState;

};


#endif /* DUMMYPHYSICALINPUT_H_ */
