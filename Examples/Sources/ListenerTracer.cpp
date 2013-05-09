/*
 * ListenerTracer.cpp
 *
 *  Created on: May 9, 2013
 *      Author: thomas
 */

#include "../ListenerTracer.h"

#include <iostream>
using namespace std;

//--------------------------------------------------------------------------------------------------------
void ListenerTracer::InputToTraceHasChanged(bool newState)
{
	if(newState == true)
	{
		cout << "Tracer says : Raising Edge !" << endl;
	}
	else
	{
		cout << "Tracer says : Falling Edge !" << endl;
	}
}

