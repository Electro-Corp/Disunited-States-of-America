/*
*/
#include <game.h>

Game::Nunticle::Nunticle(){
    scriptMan = new Scripting::ScriptManager("../assets/scripts");

    std::cout << "NUNTICLE GAME ENGINE\nit just works!\n";
}

/**
 * Load script for a gameObject
*/
void Game::Nunticle::loadScript(Engine::GameObject* obj, std::string path){
    this->scriptMan->loadScriptForObject(obj, path);
}

void Game::Nunticle::endGame(){
    // Confirm
    // Exit
    // Print bye bye
    std::cout << "Exiting Nunticle. Loser.\n";
    exit(1);
}