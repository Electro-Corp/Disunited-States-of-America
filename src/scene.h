/*
    A scene

    in the future use Boost::Serilization 
*/
#pragma once
#include <vector>
#include <gameobject.h>
namespace Engine{
    class GameObject;

    class Scene{
        private:
            std::vector<Engine::GameObject*> gameObjects;
        public:
            Scene(std::string name);

            void addObject(Engine::GameObject* object);

            std::vector<Engine::GameObject*> getObjs();
    };
}