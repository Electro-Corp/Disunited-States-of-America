/*
*/
#include <graphics/renderer.h>

Rendering::Renderer::Renderer(std::string title, int width, int height, Game::Nunticle* game){
    window = new sf::RenderWindow(sf::VideoMode(width, height), title);
    this->game = game;
}


void Rendering::Renderer::update(){
    if(window->isOpen()){
        // Handle input
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // Clear Display
        window->clear();
        // Draw

        // Display
        window->display();
    }else{
        // End the game
        game->endGame();
    }
}



Rendering::Renderer::~Renderer(){
    std::cout << "Nunticle Renderer exiting\n";
}