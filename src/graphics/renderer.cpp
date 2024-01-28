/*
*/
#include <graphics/renderer.h>

Rendering::Renderer::Renderer(std::string title, int width, int height, Game::Nunticle* game){
    window = new sf::RenderWindow(sf::VideoMode(width, height), title);
    this->game = game;
}


void Rendering::Renderer::update(Engine::Scene scene){
    if(window->isOpen()){
        // Handle input
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        this->mouseX = sf::Mouse::getPosition(*window).x;
        this->mouseY = sf::Mouse::getPosition(*window).y;

        // Clear Display
        window->clear();
        // Draw
        for (Engine::GameObject* &gameObj : scene.getObjs()){
            gameObj->update();
            window->draw(*(gameObj->getSprite()->getSprite()));
        }
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
