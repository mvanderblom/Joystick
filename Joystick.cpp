#include "Arduino.h"
#include "Joystick.h"

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
	this->_initialized = true;
}

void Joystick::debug() {
	this->_debug = true;

	Serial.print("Initialized Joystick on ");
	Serial.print("_xPin: ");
	Serial.print(_xPin);
	Serial.print(", _yPin: ");
	Serial.print(_yPin);
	Serial.print(", _swPin: ");
	Serial.println(_swPin);
}

void Joystick::log() {
	int x = analogRead(_xPin);
	int y = analogRead(_yPin);
	int sw = analogRead(_swPin);

	Serial.print("Joystick ");
	Serial.print("x: ");
	Serial.print(x);
	Serial.print(", y: ");
	Serial.print(y);
	Serial.print(", sw: ");
	Serial.println(sw);
}

boolean Joystick::enter() {
	if (!_initialized)
		Serial.println("Please call the init method on this joystick");
	return analogRead(_swPin) < 100;
}

boolean Joystick::left() {
	if (!_initialized)
		Serial.println("Please call the init method on this joystick");
	return analogRead(_xPin) < 100;
}

boolean Joystick::right() {
	if (!_initialized)
		Serial.println("Please call the init method on this joystick");
	return analogRead(_xPin) > 900;
}

boolean Joystick::up() {
	if (!_initialized)
		Serial.println("Please call the init method on this joystick");
	return analogRead(_yPin) < 100;
}

boolean Joystick::down() {
	if (!_initialized)
		Serial.println("Please call the init method on this joystick");
	return analogRead(_yPin) > 900;
}
