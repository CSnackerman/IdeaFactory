#include "GameObject.h"

GameObject::GameObject()
    :
    rects(std::vector <ColoredRect>(1))
{}

void GameObject::pushColoredRect(ColoredRect cRect) {
    rects.push_back(cRect);
}

void GameObject::initTestGameObject() {
    SDL_Rect rect {100, 100, 100, 100};
    SDL_Color color {0, 255, 0, 255};
    rects.emplace_back(ColoredRect(rect, color));
}

std::vector<ColoredRect> GameObject::getRects() { return rects; }