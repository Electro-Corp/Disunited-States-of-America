/*
    Sprite
*/
#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <graphics/renderer.h>
namespace Rendering{
    class Sprite{
        private:
            sf::Sprite sprite;
            int renderLayer;
        public:
            Sprite();
            Sprite(std::string fileName);

            sf::Sprite getSprite();
    };
}
#endif