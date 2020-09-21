#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <SDL2/SDL_rect.h>

#include "../Display.h"
#include "../Types.h"

class GameObject {
private:
    std::vector <ColoredRect> rects;
    std::vector <ColoredLine> lines;

    static int id;

protected:
    void pushColoredRect(ColoredRect cRect);
    int getId();

public:
    GameObject();

    void initTestGameObject();

    std::vector <ColoredRect> getRects();
};

#endif