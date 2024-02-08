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
    class Scene;
}
namespace Rendering{
    class Renderer;
}
namespace Game{
    // Nunticle
    class Nunticle{
        private:
        Scripting::ScriptManager* scriptMan;
        Rendering::Renderer* renderer;
        public:
        Nunticle();

        void loadScript(Engine::GameObject* object, std::string path);

        void tick(Engine::Scene);

        void changeWindowTitle(std::string);

        void initScripts();

        void endGame();
    };
}