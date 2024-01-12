/*
*/
#include <graphics/sprite.h>

Rendering::Sprite::Sprite(std::string fileName){
    // Load texture
    sf::Texture texture;
    if(!texture.loadFromFile(fileName)){
        // Error, for now just print it
        printf("Failed to load texture %s\n", fileName.c_str());
        exit(-1);
    }
}