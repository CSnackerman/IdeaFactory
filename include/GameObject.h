#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>

#include <SDL2/SDL_rect.h>

typedef std::pair <SDL_Rect, SDL_Color> ColoredRect;

class GameObject {
private:
    std::vector <ColoredRect> rects;

public:
    GameObject();

    void initTestGameObject();

    std::vector <ColoredRect> getRects();

};

#endif