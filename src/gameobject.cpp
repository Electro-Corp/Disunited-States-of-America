/*
*/
#include <gameobject.h>

Engine::GameObject::GameObject(Transform::Vector2 pos, float angle){
    this->position = pos;
    this->angle = angle;
}

Transform::Vector2 Engine::GameObject::getPos(){
    return position;
}

float Engine::GameObject::getRotation(){
    return angle;
}