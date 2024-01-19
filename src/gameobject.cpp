/*
*/
#include <gameobject.h>

Engine::GameObject::GameObject(Transform::Transform transform){
    this->transform = transform;
}

Transform::Vector2 Engine::GameObject::getPos(){
    return transform.position;
}

float Engine::GameObject::getRotation(){
    return transform.angle;
}