#include <Arduino.h>
#include <Joystick.h>

Joystick::Joystick() {
	this->_xPin = A0;
	this->_yPin = A1;
	this->_swPin = A2;
}

Joystick::Joystick(int xPin, int yPin, int swPin) {
	this->_xPin = xPin;
	this->_yPin = yPin;
	this->_swPin = swPin;
}

void Joystick::init() {
	pinMode(_xPin, INPUT);
	pinMode(_yPin, INPUT);
	pinMode(_swPin, INPUT_PULLUP);

//	Serial.print("Initialized Joystick on ");
//	Serial.print("_xPin: ");
//	Serial.print(_xPin);
//	Serial.print(", _yPin: ");
//	Serial.print(_yPin);
//	Serial.print(", _swPin: ");
//	Serial.println(_swPin);
}

bool Joystick::enter() {
	return analogRead(_swPin) < 100;
}

bool Joystick::left() {
	return analogRead(_xPin) < 100;
}

bool Joystick::right() {
	return analogRead(_xPin) > 900;
}

bool Joystick::up() {
	return analogRead(_yPin) < 100;
}

bool Joystick::down() {
	return analogRead(_yPin) > 900;
}

bool Joystick::none() {
	int x = analogRead(_xPin);
	int y = analogRead(_yPin);
	int sw = analogRead(_swPin);

	return (x > 400 && x < 600 && y > 400 && y < 600 && sw > 900);
}
