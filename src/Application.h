#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>

#include <SDL2/SDL.h>

#include "Graphics.h"
#include "SceneManager.h"


class Application {
private:
     static const std::string name;
     static bool running;

     Graphics gfx;
     SceneManager sceneManager;
     
     void handleEvents();
     void update();
     void drawScreen();

public:
     static void initSDL();
     void initialize();
     
     void run();
     void quit();
    
     static const char* getName() { return name.c_str(); }
};

#endif