/*
*/
#pragma once
#include <gameobject.h>

namespace UI{

    class Text : public Engine::GameObject {
    private:
        sf::Font font;
        sf::Text text;
    public:
        Text(std::string caption);

        void setText(std::string caption);
        void setSize(int size);

        void update() override;

        void draw(sf::RenderWindow* window) override;
    };

}