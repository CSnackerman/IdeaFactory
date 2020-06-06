#include "Display.h"
#include "Application.h"

Display::Display() 
    : 
    resolution{500, 500},
    window(nullptr)
{
    window = SDL_CreateWindow (
        Application::getName(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        resolution.width,
        resolution.height,
        windowFlags
    );
}

Display::Display(int width, int height)
    :
    resolution{width, height},
    window(nullptr)
{}

void Display::print() {
    std::string resString, flagString, format;
    
    resString = "[INFO]\tDisplay %dx%d\n";
    flagString = "[INFO]\tWindow Flags 0x%.4x\n";
    format = resString + flagString;

    printf (
        format.c_str(), 
        resolution.width, 
        resolution.height,
        windowFlags
    );
}

const int Display::getWidth() { return resolution.width; }
const int Display::getHeight() { return resolution.height; }
const int Display::getWindowFlags() { return windowFlags; }
