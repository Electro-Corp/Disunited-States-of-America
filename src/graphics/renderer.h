/*
    Rendering 
*/
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include <scene.h>
#include <game.h>
namespace Engine{
    class Scene;
}
namespace Game{
    class Nunticle;
}
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
            sf::View currentView;

            // Game Instance
            Game::Nunticle* game;
        public:
            float mouseX, mouseY;
            bool mouseDown;
            

            Renderer(std::string title, int width, int height, Game::Nunticle* game);

            // Update the render view based on the current scene
            void update(Engine::Scene scene);

            void moveView(float x, float y);

            Transform::Vector2 getWindowSize();

            ~Renderer();
    };
}