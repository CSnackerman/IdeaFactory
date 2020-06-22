#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL_video.h>

class Display {
private:
    const struct Resolution {
        const int width, height;
    } resolution;

    const int windowFlags = 
        SDL_WINDOW_SHOWN
        | SDL_WINDOW_MOUSE_FOCUS
        | SDL_WINDOW_INPUT_FOCUS
        | SDL_WINDOW_ALLOW_HIGHDPI;

    void createWindow();

protected:
    SDL_Window* window;

    Display();
    Display(const int w, const int h);

public:
    void print();

};

#endif