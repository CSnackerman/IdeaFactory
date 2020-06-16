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

    SDL_Window* window;
    SDL_Surface* surface;

    void createWindow();
    void createSurface();

public:
    Display();
    Display(const int w, const int h);

    void update();
    void print();

    const int getWidth();
    const int getHeight();
    const int getWindowFlags();
    SDL_Surface getSurface();
};

#endif