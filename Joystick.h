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
		bool enter();
		bool left();
		bool right();
		bool up();
		bool down();
		bool none();
	private:
		int _xPin, _yPin, _swPin;
		bool _initialized = false;
		bool _debug = false;
		void _checkInitialized();
};
#endif
