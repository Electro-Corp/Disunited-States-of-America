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

float Engine::GameObject::getRotation(){
    return transform.angle;
}