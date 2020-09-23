#ifndef TEMPLATE_SCENE_H
#define TEMPLATE_SCENE_H

#include <iostream>
#include <string>
#include <vector>
#include <cxxabi.h>
#include <memory>

#include "template_entity.h"
#include "../scenes/SceneKeys.h"

using namespace SceneKeys;

class Template_Scene {
private:
    std::vector<Template_Entity> gameObjects;

protected:
    Template_Scene(SceneKey);
    SceneKey key;

    void addGameObject(Template_Entity);

public:
    Template_Scene();

    std::vector<Template_Entity> getGameObjects();
};

#endif