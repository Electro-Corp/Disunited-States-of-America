/*
    Manages the game
*/
#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <iostream>

#include <scripting/scriptmanager.h>

namespace Game{
    // Nunticle
    class Nunticle{
        private:
        Scripting::ScriptManager* scriptMan;
        public:
        Nunticle();

        void endGame();
    };
}
#endif