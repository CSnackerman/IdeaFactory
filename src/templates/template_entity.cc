#include "template_entity.h"

int Template_Entity::id = -1;

Template_Entity::Template_Entity()
    :
    rects(std::vector <ColoredRect>(1))
{
    ++id;
}

void Template_Entity::pushColoredRect(ColoredRect cRect) {
    rects.push_back(cRect);
}

void Template_Entity::initTestGameObject() {
    SDL_Rect rect {100, 100, 100, 100};
    SDL_Color color {0, 255, 0, 255};
    rects.emplace_back(ColoredRect(rect, color));
}

std::vector<ColoredRect> Template_Entity::getRects() { return rects; }

int Template_Entity::getId() { return id; }