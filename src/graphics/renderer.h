/*
    Rendering 
*/
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include <game.h>

namespace Rendering{

    // Layer to render on
    enum RenderLayers{
        BACKGROUND = 0,
        MIDGROUND = 1,
        FOREGROUND = 2,
        UI = 3
    };

    class Renderer{
        private:
            sf::RenderWindow* window;

            // Game Instance
            Game::Nunticle* game;
        public:
            Renderer(std::string title, int width, int height, Game::Nunticle* game);

            void update();

            ~Renderer();
    };
}