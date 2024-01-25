/*
    Manages the game
*/
#pragma once

#include <stdlib.h>
#include <iostream>

#include <scripting/scriptmanager.h>
namespace Scripting{
    class ScriptManager;
}
namespace Engine{
    class GameObject;
}
namespace Game{
    // Nunticle
    class Nunticle{
        private:
        Scripting::ScriptManager* scriptMan;
        public:
        Nunticle();

        void loadScript(Engine::GameObject* object, std::string path);

        void endGame();
    };
}