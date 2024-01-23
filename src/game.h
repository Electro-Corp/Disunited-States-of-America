/*
    Manages the game
*/
#pragma once

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