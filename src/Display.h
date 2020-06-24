#ifndef DISPLAY_H
#define DISPLAY_H

#include <utility>

#include <SDL2/SDL_video.h>

class Display {
private:
    static const int width, height;
    static const Uint32 windowFlags;

    void createWindow();

protected:
    SDL_Window* window;
    
    Display();


public:
    void print();
    static std::pair<int, int> getWindowDimens();

};

#endif