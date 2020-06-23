#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <string>
#include <vector>

#include "GameObject.h"

class GameScene {
private:
    std::vector<GameObject> gameObjects;

public:
    GameScene();

    void addGameObject(GameObject gameObject);

    std::vector<GameObject> getGameObjects();
};

#endif