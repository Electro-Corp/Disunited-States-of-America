/*
    Rendering 
*/
#ifndef REDNERER_H
#define RENDERER_H
#include <SFML/Graphics.hpp>
#include <game.h>
#include <iostream>

namespace Rendering{
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
#endif