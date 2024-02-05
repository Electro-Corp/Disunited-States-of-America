/*
*/
#include <gameObjects/boat.h>

Game::Boat::Boat(std::string texLoc) : Engine::GameObject(texLoc){
}

void Game::Boat::update(){
    // Update transform
    this->updateTransform();
    // Update script
    this->updateScript();
}