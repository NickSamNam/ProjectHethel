#include "Notifying/RgbLed.h"

using namespace Notifying;

int redPin = 0;
int greenPin = 10;
int bluePin = 9;

void RgbLed::setup(){
	//Putting correct pins to OUTPUT pinmode
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);
}

void RgbLed::off()
{
	//Writing 0 to all pins -> off
	analogWrite(redPin, 0);
  	analogWrite(greenPin, 0);
  	analogWrite(bluePin, 0);  
}

void RgbLed::on(int r, int g, int b)
{
	setup();
	//r, g and b can have a value ranging between 0 and 255. 255 being max brightness for that particular color.
  	analogWrite(redPin, r);
  	analogWrite(greenPin, g);
  	analogWrite(bluePin, b);  
}
