#include "HardwareDigitalInputEmulator.h"
#include "ListenerTracer.h"
#include "../ListenableSampledInput.h"
#include "../DelegateBooleanParameter.h"


#include <iostream>
using namespace std;

int main() {
	cout << "main--" << endl;
	cout << "Edge tracing : we want to illustrate the input listener mechanism :" << endl;

	//build a emulated sequence
	bool sequence[] = {false,true,true, false, false, true, true};
	unsigned short sequenceSize = sizeof(sequence);
	HardwareDigitalInputEmulator emulatedInput(sequence,sequenceSize);

	//build dummmy listener and associated delegate
	ListenerTracer tracer;
	TypedDelegateBooleanParameter<ListenerTracer> handlerToTracer(tracer,&ListenerTracer::InputToTraceHasChanged);

	//build and subscribe to sampled input
	ListenableSampledInput sampledInput(emulatedInput);
	sampledInput.addListener(&handlerToTracer);

	//in a real world the emulated signal should not be "latched"
	//Acquire() operation should be associated with an OS timer
	for(unsigned short latch =0; latch <sequenceSize;  latch++)
	{
		emulatedInput.latchNextState();
		sampledInput.Acquire();
	}

	cout << "-- end main" << endl;
	return 0;
}
