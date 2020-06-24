#include "TestScene.h"

TestScene::TestScene() {
    Grid grid = {0, 0, 0, 0, 10, Grid::ALTERNATING_GRID};
    addGameObject(grid);
}