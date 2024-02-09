/*
*/
#include <game.h>

Game::DSA::DSA(){
    this->renderer = new Rendering::Renderer(std::string("Disunited States of America"), 800, 600, this);
    scriptMan = new Scripting::ScriptManager("../assets/scripts", renderer);

    std::cout << "NUNTICLE\n";
}

/**
 * Load script for a gameObject
*/
void Game::DSA::loadScript(Engine::GameObject* obj, std::string path){
    this->scriptMan->loadScriptForObject(obj, path);
}

void Game::DSA::initScripts(){
    this->scriptMan->initScripts();
}

void Game::DSA::tick(Engine::Scene scene){
    this->renderer->update(scene);
}

float Game::DSA::getTime(){
    return this->renderer->getDeltaTime();
}

void Game::DSA::changeWindowTitle(std::string title){
    this->renderer->changeTitle(title);
}

void Game::DSA::endGame(){
    // Confirm
    // Exit
    // Print bye bye
    std::cout << "Exiting Nunticle. Loser.\n";
    exit(1);
}