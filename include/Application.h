#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>

#include <SDL2/SDL.h>

#include "Display.h"

class Application {
private:
    static const std::string name;

    Display display;

    void initSDL();
    void handleEvents();
    void update();
    void drawScreen();
    void quit();

public:
    Application();

    static void run();
    static const char* getName() { return name.c_str(); }
};

#endif