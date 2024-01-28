/*
*/
#include <graphics/sprite.h>

Rendering::Sprite::Sprite(){
    
}

Rendering::Sprite::Sprite(std::string fileName){
    // Load texture
    if(!texture.loadFromFile(fileName)){
        // Error, for now just print it
        printf("Failed to load texture %s\n", fileName.c_str());
        exit(-1);
    }
    // Smooth out the texture
    texture.setSmooth(true);

    sprite.setTexture(texture);

    sprite.setOrigin(
        (sf::Vector2f)texture.getSize() / 2.f
    );
}

sf::Sprite* Rendering::Sprite::getSprite(){
    return &(this->sprite);
}
