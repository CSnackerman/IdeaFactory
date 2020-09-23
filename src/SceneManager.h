#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <string>
#include <map>

//Include GameScene implementations
#include "scenes/scene_test.h"

class SceneManager {
private:
    std::map <std::string, Template_Scene> scenes;

    void addScene(std::string name, Template_Scene scene);

public:
    Template_Scene getScene(std::string name);

    void initializeScenes();
};

#endif