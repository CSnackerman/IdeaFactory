#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>

#include <SDL2/SDL_rect.h>

#include "../Display.h"

typedef std::pair <SDL_Rect, SDL_Color> ColoredRect;

class GameObject {
private:
    std::vector <ColoredRect> rects;

protected:
    void pushColoredRect(ColoredRect cRect);

public:
    GameObject();

    void initTestGameObject();

    std::vector <ColoredRect> getRects();

};

#endif