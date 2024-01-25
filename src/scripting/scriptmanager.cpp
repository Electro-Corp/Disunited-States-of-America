/*
*/
#include <scripting/scriptmanager.h>

Scripting::Script::Script(lua_State* L) : 
    updateFunc(luabridge::getGlobal(L, "update")), 
    init(luabridge::getGlobal(L, "init")){

}   

void Scripting::Script::setGameObj(Engine::GameObject* obj){
    this->thisObj = obj;
}

void Scripting::Script::update(){
    updateFunc(thisObj);
}

Scripting::ScriptManager::ScriptManager(){
    
}

Scripting::ScriptManager::ScriptManager(std::string p_scriptPath) {   
    // Create Lua state             
    m_luaState = luaL_newstate();
    luaL_openlibs(m_luaState);

    
    exposeGameObjects();
}

void Scripting::ScriptManager::loadScriptForObject(Engine::GameObject* object, std::string path){
    for (const auto & entry : fs::directory_iterator(path)){
        // Load scripts
        std::ifstream file((char*) entry.path().u8string().c_str());
        int scriptLoadStatus = luaL_dofile(m_luaState, entry.path().u8string().c_str());

        object->script = new Script(m_luaState);
        object->script->setGameObj(object);

        /*updateFuncs.push_back(luabridge::getGlobal(m_luaState, "update"));
        initFuncs.push_back(luabridge::getGlobal(m_luaState, "init"));*/
    }
}

void Scripting::ScriptManager::exposeGameObjects(){
    printf("[ScriptManager] Expose Vector2/Transform/GameObject to Lua\n");
    // Expose Transform
    luabridge::getGlobalNamespace(m_luaState)
        .beginClass<Transform::Vector2>("Vector2")
        .addConstructor<void(*) (float, float)>()
        .addProperty("x", &Transform::Vector2::x)
        .addProperty("y", &Transform::Vector2::y)
        .endClass();

    luabridge::getGlobalNamespace(m_luaState)
        .beginClass<Transform::Transform>("Transform")
        .addConstructor<void(*) ()>()
        .addConstructor<void(*) (float, float, float)>()
        .addConstructor<void(*) (Transform::Vector2, float)>()
        .addProperty("position", &Transform::Transform::position)
        .addProperty("angle", &Transform::Transform::angle)
        .endClass();

    luabridge::getGlobalNamespace(m_luaState)
        .beginClass<Engine::GameObject>("GameObject")
        .addConstructor<void(*) ()>()
        .addConstructor<void(*) (Transform::Transform)>()
        .addFunction("getSprite", &Engine::GameObject::getSprite)
        .addProperty("transform", &Engine::GameObject::transform)
        .endClass();
}