#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "Application.h"

#define DEBUG_SET 1

// bool quit = false;

// //Prototypes
// int errorCheck(const char* label, const int success);
// void checkEvents();

//-----

int main( int argc, char* args[] ) {

	Application app;

	app.run();

	// SDL_Window* window = NULL;
	// SDL_Surface* screenSurface = NULL;

	// //Initialize SDL
	// errorCheck("SDL_Init", SDL_Init(SDL_INIT_EVERYTHING));
	
	// //Create window
	// window = SDL_CreateWindow (
	// 	"Set", 
	// 	SDL_WINDOWPOS_UNDEFINED, 
	// 	SDL_WINDOWPOS_UNDEFINED, 
	// 	display.getWidth(), 
	// 	display.getHeight(), 
	// 	display.getWindowFlags() 
	// );

	// if( window == NULL ) {
	// 	errorCheck("SDL_CreateWindow", -1);
	// 	SDL_DestroyWindow(window);
	// 	SDL_Quit();
	// 	return 1;
	// }

	// //Get window surface
	// screenSurface = SDL_GetWindowSurface(window);
	// if(screenSurface == NULL) {
	// 	errorCheck("SDL_GetWindowSurface", -1);
	// 	SDL_DestroyWindow(window);
	// 	SDL_Quit();
	// 	return 1;
	// }

	// //Run
	// while(!quit) {
	// 	checkEvents();

	// 	//Fill the surface white
	// 	SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
		
	// 	//Update the surface
	// 	SDL_UpdateWindowSurface(window);
	// }

	

	// //Destroy window
	// SDL_DestroyWindow(window);

	// //Quit SDL subsystems
	// SDL_Quit();

	return 0;
}

//-----

// int errorCheck(const char* label, const int success) {
// 	if(success < 0) {
// 		printf("[ERROR]\t%s - FAIL\n\tSDL_Error: %s\n", label, SDL_GetError());
// 		return 1;
// 	}

// 	if(DEBUG_SET) {
// 		printf("[INFO]\t%s - SUCCESS\n", label);
// 	}

// 	return 0;
// }

// void checkEvents() {
// 	SDL_Event event;
// 	while(SDL_PollEvent(&event)) {
// 		switch(event.type) {
			
// 			case SDL_QUIT:
// 				quit =  true;
// 				return;
			
// 		}
// 	}
// }