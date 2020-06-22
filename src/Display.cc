#include "Display.h"
#include "Application.h"

Display::Display() 
    : 
    resolution{500, 500},
    window(nullptr)
{
    createWindow();
}

Display::Display(int width, int height)
    :
    resolution{width, height},
    window(nullptr)

{
    createWindow();
}

void Display::createWindow() {
    window = SDL_CreateWindow (
        Application::getName(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        resolution.width,
        resolution.height,
        windowFlags
    );
}

void Display::print() {
    std::string resString, flagString, format;
    
    //Fields
    resString = "[INFO]\tDisplay %dx%d\n";
    flagString = "[INFO]\tWindow Flags 0x%.4x\n";

    //Concatenate
    format = resString + flagString;

    printf (
        format.c_str(), 
        resolution.width,
        resolution.height,
        windowFlags
    );
}


