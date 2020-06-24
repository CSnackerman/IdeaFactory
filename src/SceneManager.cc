#include "SceneManager.h"

GameScene SceneManager::getScene(std::string name) { return scenes[name]; }

void SceneManager::initializeScenes() {    
    addScene("test_scene", TestScene());
}

void SceneManager::addScene(std::string name, GameScene scene) {
    std::pair<std::string, GameScene> scenePair = std::make_pair(name, scene);
    scenes.insert(scenePair);
}