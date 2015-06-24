#include "cubeOperation.h"

// Public members

void cubeOperation::init()
{
	// Set all pins to OUTPUT and turn them off
	for(int i = 0 ; i < 20 ; i++)
	{
		pinMode(i, OUTPUT);
		digitalWrite(i, LOW);
	}
	
}

void cubeOperation::setCube(int* array, unsigned long time)
{
	unsigned long startTime = millis();
	unsigned long endTime;
	while(1)
	{
		for(int i = 0 ; i < 4 ; i++)
		{
			// Turn plane i+16
			digitalWrite(i+16, LOW);
			
			// 16 node/layer
			for(int j = 0 ; j < 16 ; j++)
			{
				int pin = (i * 16) + j;
				if(array[pin] == 1)
					digitalWrite(j, HIGH);
				else
					digitalWrite(j, LOW);
			}
			
			// Let the pattern stay for 0.2s
			delay(5);
			
			//Turn off all plane
			for(int k = 16 ; k < 20 ; k++)
				digitalWrite(k, HIGH);
		}
		endTime = millis();
		if( (endTime - startTime) > time)
			break;
	}
	// 4 layers
}

void cubeOperation::setAllOn(unsigned long time)
{
	unsigned long startTime = millis();
	unsigned long endTime;
	while(1)
	{
		for(int i = 0 ; i < 16 ; i++)
			digitalWrite(i, HIGH);
		for(int i = 16 ; i < 20 ; i++)
			digitalWrite(i, LOW);
		
		endTime = millis();
		if( (endTime - startTime) > time )
			break;
	}
	
}

void cubeOperation::setAllOff(unsigned long time)
{
	unsigned long startTime = millis();
	unsigned long endTime;
	while(1)
	{
		for(int i = 0 ; i < 16 ; i++)
			digitalWrite(i, LOW);
		for(int i = 16 ; i < 20 ; i++)
			digitalWrite(i, HIGH);
		
		endTime = millis();
		if( (endTime - startTime) > time )
			break;
	}
}