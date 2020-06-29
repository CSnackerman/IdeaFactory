#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <iostream>
#include <string>
#include <vector>
#include <cxxabi.h>
#include <memory>

#include "GameObject.h"

namespace SCENES {
    typedef const std::string SceneKey;

    SceneKey test_scene = "test_scene";
    SceneKey menu_scene = "menu_scene";
    SceneKey game_scene = "game_scene";
}

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