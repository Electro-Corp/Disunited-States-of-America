/*
    Class for boats 
*/
#ifndef MAP_H
#define MAP_H

#include <gameobject.h>

namespace Game {
    class Map : public Engine::GameObject {
    private:

    public:
        Map(std::string filePath);

        void update();
    };
}

#endif
