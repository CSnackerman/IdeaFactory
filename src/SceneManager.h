#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <string>
#include <map>

//Include GameScene implementations
#include "game_scenes/TestScene.h"

class SceneManager {
private:
    std::map <std::string, GameScene> scenes;

    void addScene(std::string name, GameScene scene);

public:
    GameScene getScene(std::string name);

    void initializeScenes();
};

#endif