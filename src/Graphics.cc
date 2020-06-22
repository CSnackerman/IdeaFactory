#include "Graphics.h"

Graphics::Graphics() 
{}

Graphics::Graphics(int width, int height) 
    :
    Display{width, height},
    renderer(nullptr),
    refreshColor{0, 0, 0, 255}
{
    renderer = SDL_CreateRenderer(Display::window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr) {
        printf("[ERROR] CreateRenderer() %s\n", SDL_GetError());
    }
}

void Graphics::setRenderDrawColor(SDL_Color color) {
    SDL_SetRenderDrawColor (
        renderer,
        color.r,
        color.g,
        color.b,
        color.a   
    );
}

void Graphics::render() {

    //Clear renderer surface
    setRenderDrawColor(refreshColor);
    SDL_RenderClear(renderer);

    SDL_Color rectColor {0, 100, 0, 255};
    SDL_Rect rect {100, 100, 100, 100};
    setRenderDrawColor(rectColor);
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
}

void Graphics::updateSurface() {
    SDL_UpdateWindowSurface(Display::window);
}