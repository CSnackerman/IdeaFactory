#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>

#include <SDL2/SDL.h>

#include "Graphics.h"

class Application {
private:
     static const std::string name;
     bool running;

     Graphics gfx;

     static void initSDL();
     
     void handleEvents();
     void update();
     void drawScreen();

public:
     Application();

     static void initialize();
     void run();
     void quit();
    
     static const char* getName() { return name.c_str(); }
};

#endif