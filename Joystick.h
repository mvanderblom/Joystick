#ifndef Joystick_h
#define Joystick_h

class Joystick
{
	public:
		Joystick();
		Joystick(int xPin, int yPin, int swPin);
		void debug();
		void init();
		void log();
		boolean enter();
		boolean left();
		boolean right();
		boolean up();
		boolean down();
		boolean none();
	private:
		int _xPin, _yPin, _swPin;
		boolean _initialized = false;
		boolean _debug = false;
		void _checkInitialized();
};
#endif
