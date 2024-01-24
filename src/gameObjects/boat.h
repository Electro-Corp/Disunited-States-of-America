/*
    Class for boats 
*/
#ifndef BOAT_H
#define BOAT_H

#include <gameobject.h>

namespace Game {
    class Boat : public Engine::GameObject {
    private:

    public:
        Boat(std::string filePath);

        void update();
    };
}

#endif
