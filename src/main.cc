#include <SDL2/SDL.h>
#include <stdio.h>

#include "Application.h"

int main( int argc, char* args[] ) {

	Application::initSDL();

	Application app;
	
	app.initialize();
	app.run();
	app.quit();

	return 0;
}