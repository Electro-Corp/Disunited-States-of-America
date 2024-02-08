#include <gameObjects/ui/text.h>

UI::Text::Text(std::string caption){
    drawable = false;
    if(!font.loadFromFile("../assets/fonts/playball.ttf")){

    }
    text.setFont(font);
    text.setString(caption);
    text.setFillColor(sf::Color::White);
}

void UI::Text::setText(std::string caption){
    text.setString(caption);
}

void UI::Text::setSize(int size){
    text.setCharacterSize(size);
}

void UI::Text::update(){
    this->text.setPosition(
        sf::Vector2f(
            this->transform.position.x,
            this->transform.position.y
        )
    );

    updateScript();
}

void UI::Text::draw(sf::RenderWindow* window){
    window->draw(text);
}