#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <iostream>
#include <string>
#include <vector>
#include <cxxabi.h>
#include <memory>

#include "GameObject.h"
#include "../game_scenes/SCENES.h"

using namespace SCENES;

class GameScene {
private:
    std::vector<GameObject> gameObjects;

protected:
    GameScene(SceneKey);
    SceneKey key;

    void addGameObject(GameObject);

public:
    GameScene();

    std::vector<GameObject> getGameObjects();
};

#endif