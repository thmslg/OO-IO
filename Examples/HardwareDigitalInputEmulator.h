#ifndef HARDWAREDIGITALINPUTEMULATOR_H_
#define HARDWAREDIGITALINPUTEMULATOR_H_

#include "../DigitalInput.h"

class HardwareDigitalInputEmulator: public DigitalInput
{
public:
	//--------------------------------------------------------------------------------------------------------
	//! \pre 'sequence' is NOT NULL
	//! 'sequenceSize' is the number of element contained into sequence
	//! \post Input is set to the first element of the sequence.
	explicit HardwareDigitalInputEmulator(bool * const sequence, unsigned short sequenceSize):
	_sequence(sequence),
	_sequenceSize(sequenceSize),
	_sequenceIndex(0)
	{}

	//--------------------------------------------------------------------------------------------------------
	virtual ~HardwareDigitalInputEmulator(){}

	//--------------------------------------------------------------------------------------------------------
	//! \pre None
	//! \post Will change the state of the input with the next element into the sequence
	//! ( see contsruction parameter)
	//! if the end of the sequence is reach, we just restart to the beginning of the sequence
	//! (circular sequence)
	void latchNextState();

	//--------------------------------------------------------------------------------------------------------
	//! \pre See base class
	//! \post See base class
	virtual bool GetState() const;

private:
	bool * const _sequence;
	unsigned short _sequenceSize;
	//where we are inside the sequence
	unsigned short _sequenceIndex;
};

#endif /* HARDWAREDIGITALINPUTEMULATOR_H_ */
