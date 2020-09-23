#include "template_scene.h"

Template_Scene::Template_Scene()
    :
    gameObjects(std::vector<Template_Entity>(1))
{}

Template_Scene::Template_Scene(SceneKey key) : key(key) {}

void Template_Scene::addGameObject(Template_Entity gameObject) {
    gameObjects.push_back(gameObject);
}

std::vector<Template_Entity> Template_Scene::getGameObjects() { return gameObjects; }