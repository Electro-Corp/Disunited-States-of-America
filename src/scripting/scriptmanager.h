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
#include <gameobject.h>
#include <transform.h>
#include <gameObjects/boat.h>
#include <graphics/sprite.h>
#include <game.h>

namespace Scripting{
    class ScriptManager{
        private:
            lua_State* m_luaState;
            std::vector<luabridge::LuaRef> initFuncs;
            std::vector<luabridge::LuaRef> updateFuncs;
        public:
            ScriptManager();
            ScriptManager(std::string p_scriptPath);
    };
};

#endif