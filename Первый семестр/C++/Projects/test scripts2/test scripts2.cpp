#include <iostream>
#include <locale>
#include <string>
#include <print>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif 

char pressing() {
	#ifdef _WIN32
	return static_cast<char>(_getch());

	#else
	char pressed key = 0;
	struct termios old settings = { 0 };
	if (tcgetattr(0, &old settings) < 0) perror("tcsetattr()");
	#endif
}