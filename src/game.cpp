/*
*/
#include <game.h>

Game::Nunticle::Nunticle(){
    this->renderer = new Rendering::Renderer(std::string("Nunticle"), 800, 600, this);
    scriptMan = new Scripting::ScriptManager("../assets/scripts", renderer);

    std::cout << "NUNTICLE GAME ENGINE\nit just works!\n";
}

/**
 * Load script for a gameObject
*/
void Game::Nunticle::loadScript(Engine::GameObject* obj, std::string path){
    this->scriptMan->loadScriptForObject(obj, path);
}

void Game::Nunticle::initScripts(){
    this->scriptMan->initScripts();
}

void Game::Nunticle::tick(Engine::Scene scene){
    this->renderer->update(scene);
}

void Game::Nunticle::endGame(){
    // Confirm
    // Exit
    // Print bye bye
    std::cout << "Exiting Nunticle. Loser.\n";
    exit(1);
}