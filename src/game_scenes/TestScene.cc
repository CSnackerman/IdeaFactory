#include "TestScene.h"

TestScene::TestScene()
    :
    GameScene(SCENES::test_scene)  
{
    int shrink = 50;
    int width = Display::getWindowDimens().first - shrink * 2;
    int height = Display::getWindowDimens().second - shrink * 2;

    Grid grid {shrink, shrink, width, height, 50, Grid::LINE_GRID};

    // Grid grid = {0, 0, 0, 0, 50, Grid::LINE_GRID};
    addGameObject(grid);
}