/*
    Sprite
*/
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <graphics/renderer.h>

namespace Rendering{
    class Sprite{
        private:
            sf::Texture texture;
            sf::Sprite sprite;
            int renderLayer;
        public:
            Sprite();
            Sprite(std::string fileName);

            // Return the SFML sprite
            sf::Sprite* getSprite();
    };
}