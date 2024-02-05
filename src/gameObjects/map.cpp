/*
*/
#include <gameObjects/map.h>

Game::Map::Map(std::string texLoc) : Engine::GameObject(texLoc){

}

void Game::Map::update(){
    // Update transform
    this->updateTransform();
    // Update script
    this->updateScript();
}