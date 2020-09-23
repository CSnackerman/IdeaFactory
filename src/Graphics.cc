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

void Graphics::render(Template_Scene scene, RenderMode mode) {
    setRenderDrawColor(refreshColor);
    SDL_RenderClear(renderer);

    switch(mode) {
        case FILL:
            renderFill(scene);
            break;

        case OUTLINE:
            renderOutline(scene);
            break;

        default:
            renderFill(scene);
    }

    SDL_RenderPresent(renderer);
}

void Graphics::renderFill(Template_Scene scene) {
    for(Template_Entity& gObject : scene.getGameObjects()) {
        for(ColoredRect& cRect : gObject.getRects()) {
            
            SDL_Rect rect = cRect.first;
            SDL_Color color = cRect.second;

            setRenderDrawColor(color);
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

void Graphics::renderOutline(Template_Scene scene) {
    for(Template_Entity& gObject : scene.getGameObjects()) {
        for(ColoredRect& cRect : gObject.getRects()) {
            
            SDL_Rect rect = cRect.first;
            SDL_Color color = cRect.second;

            setRenderDrawColor(color);
            SDL_RenderDrawRect(renderer, &rect);
        }
    }
}
