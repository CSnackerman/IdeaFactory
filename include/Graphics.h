#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

#include "Display.h"
#include "GameScene.h"

class Graphics : protected Display {
private:
    SDL_Renderer* renderer;
    SDL_Color refreshColor;

    void setRenderDrawColor(SDL_Color color);

public:
    Graphics();
    Graphics(int width, int height);

    void render(GameScene scene);
};

#endif