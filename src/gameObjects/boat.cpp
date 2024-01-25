/*
*/
#include <gameObjects/boat.h>

Game::Boat::Boat(std::string texLoc){
    this->sprite = new Rendering::Sprite(texLoc);
}

void Game::Boat::update(){
    // Update transform
    this->updateTransform();
    // Update script
    this->updateScript();
}