#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

#include "Display.h"
#include "templates/template_scene.h"

class Graphics : protected Display {
private:
    SDL_Renderer* renderer;
    SDL_Color refreshColor;

    void setRenderDrawColor(SDL_Color color);
    void renderFill(Template_Scene);
    void renderOutline(Template_Scene);

public:
    enum RenderMode { FILL, OUTLINE };
    
    Graphics();

    void render(Template_Scene, RenderMode);
};

#endif