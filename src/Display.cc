#include "Display.h"
#include "Application.h"

//Static init
const int Display::width = 800;
const int Display::height = 800;

const Uint32 Display::windowFlags = 
    SDL_WINDOW_SHOWN
    | SDL_WINDOW_MOUSE_FOCUS
    | SDL_WINDOW_INPUT_FOCUS
    | SDL_WINDOW_ALLOW_HIGHDPI;

Display::Display() 
    :
    window(nullptr)
{
    createWindow();

    printDebug();
}

void Display::createWindow() {
    window = SDL_CreateWindow (
        Application::getName(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        windowFlags
    );
}

void Display::printDebug() {

    if(!DEBUG_DISPLAY)
        return;

    std::string resString, flagString, format;
    
    //Fields
    resString = "[DISPLAY]\n  Resolution %dx%d\n";
    flagString = "  Window Flags 0x%.4x\n\n";

    //Concatenate
    format = resString + flagString;

    printf (
        format.c_str(),
        width,
        height,
        windowFlags
    );
}

std::pair<int, int> Display::getWindowDimens() { return std::make_pair(width, height); }


