#include "Application.h"

int main() {

	Application::initSDL();

	Application app;
	
	app.setup();
	app.run();
	app.quit();

	return 0;
}