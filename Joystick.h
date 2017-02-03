#ifndef Joystick_h
#define Joystick_h

class Joystick
{
	public:
		Joystick();
		Joystick(int xPin, int yPin, int swPin);
		void init();
		bool enter();
		bool left();
		bool right();
		bool up();
		bool down();
		bool none();
	private:
		int _xPin, _yPin, _swPin;
};
#endif
