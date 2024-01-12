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
            Transform::Vector2 position;
            float angle;

            Rendering::Sprite sprite;   
        public:
            GameObject(Transform::Vector2, float);

            Transform::Vector2 getPos();
            float getRotation();

            // They derive!
            virtual void update() = 0; 
    };
}
#endif