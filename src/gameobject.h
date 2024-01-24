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
    /**
     * A gameObject 
    */
    class GameObject{
        private:
        protected:
            Rendering::Sprite* sprite;
        public:
            Transform::Transform transform;
            
            GameObject();
            GameObject(Transform::Transform transform);

            // Get position
            Transform::Vector2 getPos();
            // Get rotation
            float getRotation();

            // Return the sprite
            Rendering::Sprite* getSprite();

            void updateTransform();

            // They derive!
            virtual void update() = 0; 
    };
}