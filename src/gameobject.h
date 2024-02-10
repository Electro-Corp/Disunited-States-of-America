/*
    GameObject, a thing in the world
*/
#pragma once
#include <transform.h>
#include <graphics/sprite.h>
namespace Rendering{
    class Sprite;
}
namespace Scripting{
    class Script;
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
            Scripting::Script* script;
            Transform::Transform transform;

            bool drawable = false;

            GameObject();
            GameObject(Transform::Transform transform);
            GameObject(std::string texLoc);

            // Get position
            Transform::Vector2 getPos();
            // Get rotation
            float getRotation();

            // Return the sprite
            Rendering::Sprite* getSprite();

            void updateScript();
            void updateTransform();

            virtual void draw(sf::RenderWindow* window);

            // They derive!
            virtual void update(); 
    };
}