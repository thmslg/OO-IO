#ifndef FILTEREDINPUT_H_
#define FILTEREDINPUT_H_

#include "Input.h"
class SimpleTimer;

class FilteredInput : public Input {
public:
	//------------------------------------------------------------------------------------------------------------
	//! \pre "inputToFilter" Pointer to input to filter
	//!		"filteringTime" should be > 0, compliant with timer in ms
	//!		"filteredActiveState" edge where filter will be applied
	//!		"timer" pointer to timer to use
	//! \post None
	explicit FilteredInput(Input & inputToFilter,
							int filteringTime,
							bool filteredActiveState,
							SimpleTimer & timer);
	//------------------------------------------------------------------------------------------------------------
	virtual ~FilteredInput();

	//------------------------------------------------------------------------------------------------------------
	//! \pre  None
	//! \post ...
	virtual bool GetState() const;

	void ChangeInversion(bool inversion);

private:
	//------------------------------------------------------------------------------------------------------------
	//! \pre
	//! \post
	void inputHasChanged(bool newState);

	//------------------------------------------------------------------------------------------------------------
	//! \pre
	//! \post
	void timerElapsed(bool newState);

//	// pointer to input to filter
	Input & _inputToFilter;
//
//	//timer used for filtering
	SimpleTimer & _simpleTimer;

//	// Delegate used for input subscribing
	TypedDelegate<FilteredInput> _inputDelegate;

	// current state of the filtered input
	bool _filteredState;

	// filter timing
	int _filteringTime;

	// When state changed, filtering start on this edge
	bool _ActiveState;

//	// delegate to transmit to the timer
	TypedDelegate<FilteredInput> _simpleTimerDelegate;
};

#endif /* FILTEREDINPUT_H_ */
