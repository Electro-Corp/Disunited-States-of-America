/*
*/
#include <gameObjects/boat.h>

Game::Boat::Boat(std::string texLoc) : Engine::GameObject(){
    this->sprite = new Rendering::Sprite(texLoc);
    this->drawable = true;
}

void Game::Boat::update(){
    // Update transform
    this->updateTransform();
    // Update script
    this->updateScript();
}