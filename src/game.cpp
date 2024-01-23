/*
*/
#include <game.h>

Game::Nunticle::Nunticle(){
    scriptMan = new Scripting::ScriptManager("../assets/scripts");

    std::cout << "NUNTICLE GAME ENGINE\nit just works!\n";
}

void Game::Nunticle::endGame(){
    // Confirm
    // Exit
    // Print bye bye
    std::cout << "Exiting Nunticle. Loser.\n";
    exit(1);
}