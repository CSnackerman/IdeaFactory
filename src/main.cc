#include "Application.h"

int main() {

	Application::initSDL();

	Application app;
	
	app.initialize();
	app.run();
	app.quit();

	return 0;
}