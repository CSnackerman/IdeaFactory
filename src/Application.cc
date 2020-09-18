#include "Application.h"

const std::string Application::name = "Set";
bool Application::running = true;

void Application::initSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    }
}

void Application::setup() {
    sceneManager.initializeScenes();
}

void Application::handleEvents() {
    SDL_Event e;
    while(SDL_PollEvent(&e) != 0) {

        switch(e.type) {

            case SDL_QUIT:
                running = false;
                break;

        }
    }
}

void Application::update() {

}

void Application::drawScreen() {
    gfx.render(sceneManager.getScene(SCENES::test_scene),  Graphics::RenderMode::FILL);
}

void Application::quit() {
    SDL_Quit();
}


void Application::run() {

    while(running) {
        handleEvents();
        update();
        drawScreen();
    }
}