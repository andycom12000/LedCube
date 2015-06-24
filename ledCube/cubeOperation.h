#ifndef cubeOoperation_h
#define cubeOoperation_h

#include <Arduino.h>

#define LED_ON 1
#define LED_OFF 0

class cubeOperation{
public:
	// Initialize all LED pins
	void init();
	
	// Set the some LED ON/OFF
	void setCube(int* array, unsigned long time);
	
	// Set all LED ON
	void setAllOn(unsigned long time);
	
	// Set all LED OFF
	void setAllOff(unsigned long time);
};

#endif