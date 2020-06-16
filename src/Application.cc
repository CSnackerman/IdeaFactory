#include "Application.h"

const std::string Application::name = "Set";

Application::Application()
    :
    display(Display(800, 600)),
    running(true)
{}

void Application::initSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    }
}

void Application::initialize() {
    initSDL();
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
    display.update();
}

void Application::quit() {

}


void Application::run() {
    while(running) {
        handleEvents();
        update();
        drawScreen();
    }
}