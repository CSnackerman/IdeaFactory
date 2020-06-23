#include "SceneManager.h"

GameScene SceneManager::getScene(std::string name) { return scenes[name]; }

void SceneManager::addTestScene() {
    GameObject testObject;
    testObject.initTestGameObject();

    GameScene testScene;
    testScene.addGameObject(testObject);

    scenes.insert(std::make_pair("game_scene", testScene));
}