#include "TestScene.h"

TestScene::TestScene()
    :
    GameScene(SCENES::test_scene) //assign SceneKey
{   
    // Instantiate game_object(s)
    Grid_Fullscreen fullscreenGrid(25, Grid::LINE_GRID);

    // Populate this scene
    addGameObject(fullscreenGrid);
}