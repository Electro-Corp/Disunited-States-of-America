/*
*/
#include <game.h>

Game::Nunticle::Nunticle(){
    scriptMan = new Scripting::ScriptManager("../assets/scripts");
}

void Game::Nunticle::endGame(){
    // Confirm
    // Exit
    // Print bye bye
    std::cout << "Exiting Nunticle. Loser.\n";
    exit(1);
}