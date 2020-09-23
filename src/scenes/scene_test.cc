#include "scene_test.h"

Scene_Test::Scene_Test()
    :
    Template_Scene(scene_test) //assign SceneKey
{   
    // Instantiate game_object(s)
    Grid_Fullscreen fullscreenGrid(50, Grid::ALTERNATING_GRID);

    Grid_Relative relativeGrid(3, 12, 12, 75, 75, Grid::ALTERNATING_GRID);

    // Populate this scene
    addGameObject(relativeGrid);
}