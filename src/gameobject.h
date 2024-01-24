/*
    GameObject, a thing in the world
*/
#pragma once
#include <transform.h>
#include <graphics/sprite.h>
namespace Rendering{
    class Sprite;
}
// Gameobject
namespace Engine {
    class GameObject{
        private:
            Transform::Transform transform;
        protected:
            Rendering::Sprite* sprite;
        public:
            GameObject();
            GameObject(Transform::Transform transform);

            Transform::Vector2 getPos();
            float getRotation();

            Rendering::Sprite* getSprite();

            // They derive!
            virtual void update() = 0; 
    };
}