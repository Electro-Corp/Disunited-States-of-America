/*
*/
#include <scripting/scriptmanager.h>

Scripting::ScriptManager::ScriptManager(){
    
}

Scripting::ScriptManager::ScriptManager(std::string p_scriptPath) {   
    // Create Lua state             
    m_luaState = luaL_newstate();
    luaL_openlibs(m_luaState);

    for (const auto & entry : fs::directory_iterator(p_scriptPath)){
        // Load scripts
        std::ifstream file((char*) entry.path().u8string().c_str());
        int scriptLoadStatus = luaL_dofile(m_luaState, entry.path().u8string().c_str());

        updateFuncs.push_back(luabridge::getGlobal(m_luaState, "update"));
        initFuncs.push_back(luabridge::getGlobal(m_luaState, "init"));
    }
}