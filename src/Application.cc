#include "Application.h"

const std::string Application::name = "Set";

Application::Application() 
    :
    display(Display(800, 600))
{
    initSDL();
}

void Application::initSDL() {
    SDL_Init(SDL_INIT_EVERYTHING);
}

void Application::handleEvents() {

}

void Application::update() {

}

void Application::drawScreen() {

}

void Application::quit() {

}


void Application::run() {
    std::cout << name << " run" << std::endl;
}