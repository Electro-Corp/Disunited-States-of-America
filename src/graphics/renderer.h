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
    class DSA;
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
            sf::Clock clock;


            // Game Instance
            Game::DSA* game;
        public:
            float mouseX, mouseY, mouseDelta;
            bool mouseDown;
            

            Renderer(std::string title, int width, int height, Game::DSA* game);

            // Update the render view based on the current scene
            void update(Engine::Scene scene);

            void moveView(float x, float y);
            
            void setView(float x, float y);

            void zoomView(float delta);

            void rotateView(float delta);

            void changeTitle(std::string);

            Transform::Vector2 getWindowSize();

            float getDeltaTime();

            ~Renderer();
    };
}