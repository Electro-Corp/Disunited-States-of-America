#ifndef COUNTY_H
#define COUNTY_H

#include <gameobject.h>
#include <utils/jsonReader.h>
#include <vector>
#include <exception>

namespace Game {
    class CountyAreaPoint{
        public:
        float x, y;
    };
    class County : public Engine::GameObject {
    private:
        sf::VertexArray county;
        bool error;
    public:
        County(std::string filePath);

        void draw(sf::RenderWindow* window) override;

        void update();
    };
}
#endif