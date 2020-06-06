#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>

#include <SDL2/SDL_video.h>

class Display {
private:
    const struct Resolution {
        const int width, height;
    } resolution;

    const Uint32 windowFlags = 
        SDL_WINDOW_SHOWN
        | SDL_WINDOW_MOUSE_FOCUS
        | SDL_WINDOW_INPUT_FOCUS
        | SDL_WINDOW_ALLOW_HIGHDPI;

    SDL_Window* window;

public:
    Display();
    Display(const int w, const int h);

    const int getWidth();
    const int getHeight();
    const int getWindowFlags();
    
    void print();

};

#endif