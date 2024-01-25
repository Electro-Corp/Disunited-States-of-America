/*
*/
#include <gameobject.h>

Engine::GameObject::GameObject(){
    
}
Engine::GameObject::GameObject(Transform::Transform transform){
    this->transform = transform;
}

Transform::Vector2 Engine::GameObject::getPos(){
    return transform.position;
}

Rendering::Sprite* Engine::GameObject::getSprite(){
    return sprite;
}

void Engine::GameObject::updateTransform(){
    // Set position based on Transform
    this->sprite->getSprite()->setPosition(
        sf::Vector2f(
            this->transform.position.x,
            this->transform.position.y
        )
    );
    // Set angle based on Transform 
    this->sprite->getSprite()->setRotation(
        this->getRotation()
    );
}

float Engine::GameObject::getRotation(){
    return transform.angle;
}

void Engine::GameObject::update(){
    updateTransform();
}