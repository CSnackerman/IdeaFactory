#include "SceneManager.h"

Template_Scene SceneManager::getScene(std::string name) { return scenes[name]; }

void SceneManager::initializeScenes() {    
    addScene("scene_test", Scene_Test());
}

void SceneManager::addScene(std::string name, Template_Scene scene) {
    std::pair<std::string, Template_Scene> scenePair = std::make_pair(name, scene);
    scenes.insert(scenePair);
}