/*
*/
#include <gameobject.h>

Engine::GameObject::GameObject(){
    
}
Engine::GameObject::GameObject(Transform::Transform transform){
    this->transform = transform;
}
Engine::GameObject::GameObject(std::string texLoc){
    this->sprite = new Rendering::Sprite(texLoc);
    this->drawable = true;
}

Transform::Vector2 Engine::GameObject::getPos(){
    return transform.position;
}

Rendering::Sprite* Engine::GameObject::getSprite(){
    return sprite;
}

void Engine::GameObject::updateTransform(){
    if(drawable){
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
        // Set scale
        this->sprite->getSprite()->setScale(
            sf::Vector2f(
                this->transform.scale.x,
                this->transform.scale.y
            )
        );
    }
}

void Engine::GameObject::draw(sf::RenderWindow* window){
    if(drawable){
        window->draw(*(this->getSprite()->getSprite()));
    }
}

void Engine::GameObject::updateScript(){
    if(this->script){
        this->script->update();
    }
}

float Engine::GameObject::getRotation(){
    return transform.angle;
}

void Engine::GameObject::update(){
    updateTransform();
    updateScript();
}
