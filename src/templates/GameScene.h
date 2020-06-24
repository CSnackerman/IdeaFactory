#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <string>
#include <vector>

#include "GameObject.h"

class GameScene {
private:
    std::vector<GameObject> gameObjects;

protected:
    void addGameObject(GameObject gameObject);

public:
    GameScene();

    std::vector<GameObject> getGameObjects();
};

#endif