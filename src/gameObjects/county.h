#pragma once

#include <gameobject.h>
#include <utils/jsonReader.h>
#include <vector>
#include <exception>
#include <utils/stateColor.h>

#include <random>

namespace Game {
    class CountyAreaPoint{
        public:
        float x, y;
    };
    class County : public Engine::GameObject {
    private:
        sf::VertexArray county;
        sf::VertexArray lines;
        bool error;
    public:
        County(std::string filePath, StateColorManagerTemp *manager);

        void draw(sf::RenderWindow* window) override;

        void highlightColor();

        void defaultColor();

    };
}