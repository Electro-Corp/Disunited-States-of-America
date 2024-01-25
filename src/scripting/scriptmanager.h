/*
    Script manager
*/
#ifndef SCRIPTMAN_H
#define SCRIPTMAN_H
#include <vector>
#include <iostream>
#include <filesystem>
#include <memory>
#include <fstream>
namespace fs = std::filesystem;

extern "C"
{
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
}

#include <LuaBridge/LuaBridge.h>

// Include things that need to be exposed to Lua
#include <scene.h>
#include <gameobject.h>
namespace Engine{
    class GameObject;
}
namespace Scripting{
    class Script{
        private:
            luabridge::LuaRef init;
            luabridge::LuaRef updateFunc;

            Engine::GameObject* thisObj;
        public:
            Script(lua_State* L);

            void setGameObj(Engine::GameObject*);

            void update();
    };

    class ScriptManager{
        friend Script; 
        private:
            lua_State* m_luaState;
            std::vector<luabridge::LuaRef> initFuncs;
            std::vector<luabridge::LuaRef> updateFuncs;
        public:
            ScriptManager();
            ScriptManager(std::string p_scriptPath);

            void loadScriptForObject(Engine::GameObject* object, std::string path);

            // Expose GameObject features to Lua
            void exposeGameObjects();

            // Expose Scene features to Lua
            void exposeScene();
    };
};

#endif