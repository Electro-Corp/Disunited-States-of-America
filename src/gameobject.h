/*
    GameObject, a thing in the world
*/
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <transform.h>
#include <graphics/sprite.h>
namespace Engine {
    class GameObject{
        private:
            Transform::Transform transform;

            Rendering::Sprite sprite;
        public:
            GameObject(Transform::Transform transform);

            Transform::Vector2 getPos();
            float getRotation();

            // They derive!
            virtual void update() = 0; 
    };
}
#endif