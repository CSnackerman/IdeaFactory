#include "Graphics.h"

Graphics::Graphics() 
    :
    renderer(nullptr),
    refreshColor{1, 2, 3, 255}
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

void Graphics::render(GameScene scene) {
    //Clear renderer surface
    setRenderDrawColor(refreshColor);
    SDL_RenderClear(renderer);

    //Render every ColoredRect of every GameObject of every GameScene
    for(GameObject& gObject : scene.getGameObjects()) {
        for(ColoredRect& cRect : gObject.getRects()) {
            
            SDL_Rect rect = cRect.first;
            SDL_Color color = cRect.second;

            setRenderDrawColor(color);
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    SDL_RenderPresent(renderer);
}