#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <string>
#include <map>

#include "GameScene.h"

class SceneManager {
private:
    std::map <std::string, GameScene> scenes;

public:
    GameScene getScene(std::string name);

    void addTestScene();
};

#endif