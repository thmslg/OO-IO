#ifndef SAMPLABLE_H_
#define SAMPLABLE_H_

class Samplable {
public:
	//--------------------------------------------------------------------------------------------------------
	//! \pre Acquirment should be possible and non blocking.
	//! \post The state of the samplable will be analysed, and transmitted if needed
	//! to the listeners.
	virtual void Acquire() = 0 ;

private:
};

#endif /* SAMPLABLE_H_ */
