/*
*/
#include <gameObjects/map.h>

Game::Map::Map(std::string texLoc) : Engine::GameObject(){
    this->sprite = new Rendering::Sprite(texLoc);
    this->drawable = true;
}

void Game::Map::update(){
    // Update transform
    this->updateTransform();
    // Update script
    this->updateScript();
}