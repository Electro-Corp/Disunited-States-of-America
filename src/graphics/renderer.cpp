/*
*/
#include <graphics/renderer.h>

Rendering::Renderer::Renderer(std::string title, int width, int height, Game::Nunticle* game){
    window = new sf::RenderWindow(sf::VideoMode(width, height), title);
    this->currentView = window->getDefaultView();
    this->game = game;
}


void Rendering::Renderer::update(Engine::Scene scene){
    if(window->isOpen()){
        // Handle input
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::Resized) {
                currentView.setSize({
                        static_cast<float>(event.size.width),
                        static_cast<float>(event.size.height)
                });
            } else if (event.type == sf::Event::MouseWheelMoved){
                mouseDelta = event.mouseWheel.delta;
            }
        }

        this->mouseX = sf::Mouse::getPosition(*window).x;
        this->mouseY = sf::Mouse::getPosition(*window).y;
      
        this->mouseDown = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        

        window->setView(currentView);

        // Clear Display    
        window->clear();
        // Draw
        for (Engine::GameObject* gameObj : scene.getObjs()){
            gameObj->update();
            //if(gameObj->drawable)
            gameObj->draw(window);
                //window->draw(*(gameObj->getSprite()->getSprite()));
        }
        // Display
        window->display();
    }else{
        // End the game
        game->endGame();
    }
}

float Rendering::Renderer::getDeltaTime(){
    float time = clock.getElapsedTime().asSeconds();
    return time;
}

void Rendering::Renderer::moveView(float x, float y){
    currentView.move(x, y);
}

void Rendering::Renderer::zoomView(float delta){
    currentView.zoom(delta);
    this->mouseDelta = 0.0f;
}

void Rendering::Renderer::rotateView(float delta){
    currentView.rotate(delta);
}
Transform::Vector2 Rendering::Renderer::getWindowSize(){
    return Transform::Vector2(window->getSize().x, window->getSize().y);
}

void Rendering::Renderer::changeTitle(std::string title){
    window->setTitle(title);
}

Rendering::Renderer::~Renderer(){
    std::cout << "Nunticle Renderer exiting\n";
}
