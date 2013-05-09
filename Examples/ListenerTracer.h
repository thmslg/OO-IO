/*
 * ListenerTracer.h
 *
 *  Created on: May 9, 2013
 *      Author: thomas
 */

#ifndef LISTENERTRACER_H_
#define LISTENERTRACER_H_

class ListenerTracer
{
public:
	ListenerTracer(){}
	virtual ~ListenerTracer(){}
	//--------------------------------------------------------------------------------------------------------
	//! \pre
	//! \post
	void InputToTraceHasChanged(bool newState);
};

#endif /* LISTENERTRACER_H_ */
