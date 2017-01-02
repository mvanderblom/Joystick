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
	_checkInitialized();
	return analogRead(_swPin) < 100;
}

boolean Joystick::left() {
	_checkInitialized();
	return analogRead(_xPin) < 100;
}

boolean Joystick::right() {
	_checkInitialized();
	return analogRead(_xPin) > 900;
}

boolean Joystick::up() {
	_checkInitialized();
	return analogRead(_yPin) < 100;
}

boolean Joystick::down() {
	_checkInitialized();
	return analogRead(_yPin) > 900;
}

boolean Joystick::none() {
	int x = analogRead(_xPin);
	int y = analogRead(_yPin);
	int sw = analogRead(_swPin);

	return (x > 400 && x < 600 && y > 400 && y < 600 && sw > 900);
}

void Joystick::_checkInitialized() {
	if (!_initialized)
		Serial.println("Please call the init method on this joystick");
}
