#include "TestScene.h"

TestScene::TestScene()
    :
    GameScene(SCENES::test_scene) //assign SceneKey
{   
    // Instantiate game_object(s)
    Grid_Fullscreen fullscreenGrid(50, Grid::ALTERNATING_GRID);

    Grid_Relative relativeGrid(3, 12, 12, 75, 75, Grid::ALTERNATING_GRID);

    // Populate this scene
    addGameObject(relativeGrid);
}