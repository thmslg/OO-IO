#ifndef DIGITALOUTPUT_H_
#define DIGITALOUTPUT_H_

//--------------------------------------------------------------------------------------------------------
//! This class is responsible to encapsulate the way we are driving the outputs.
//! Use this interface in your application layer to avoid any dirty dependencies to your hardware layer.
// We decided to NOT redefine the type DigitalState, but use bool type instead.
// LowState = false and HighState = true
class DigitalOuput {
public:
	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post The logical state of the ouput is high.
	void Set();
	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post The logical state of the ouput is low.
	void Reset();
};


#endif /* DIGITALOUTPUT_H_ */
