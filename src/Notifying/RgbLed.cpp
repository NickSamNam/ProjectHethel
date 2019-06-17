#include "Notifying/RgbLed.h"

using namespace Notifying;

RgbLed::RgbLed(int redPin, int greenPin, int bluePin){
	this->redPin = redPin;
	this->greenPin = greenPin;
	this->bluePin = bluePin;

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
	//r, g and b can have a value ranging between 0 and 255. 255 being max brightness for that particular color.
  	analogWrite(redPin, r);
  	analogWrite(greenPin, g);
  	analogWrite(bluePin, b);  
}
