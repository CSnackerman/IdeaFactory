#include "GameScene.h"

GameScene::GameScene()
    :
    gameObjects(std::vector<GameObject>(1))
{}

void GameScene::addGameObject(GameObject gameObject) {
    gameObjects.push_back(gameObject);
}

std::vector<GameObject> GameScene::getGameObjects() { return gameObjects; }