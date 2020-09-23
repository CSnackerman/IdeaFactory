#ifndef TEMPLATE_ENTITY_H
#define TEMPLATE_ENTITY_H

#include <vector>
#include <SDL2/SDL_rect.h>

#include "../Display.h"
#include "../Types.h"

class Template_Entity {
private:
    std::vector <ColoredRect> rects;
    std::vector <ColoredLine> lines;

    static int id;

protected:
    void pushColoredRect(ColoredRect cRect);
    int getId();

public:
    Template_Entity();

    void initTestGameObject();

    std::vector <ColoredRect> getRects();
};

#endif