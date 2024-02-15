#include <gameObjects/county.h>


Game::County::County(std::string filename, StateColorManagerTemp* manager) : Engine::GameObject(){
    drawable = false;
    JsonReader tmp(filename);
    Json::Value val = tmp.read();
    int size = val["POINTS"].size();
    county = sf::VertexArray(sf::TriangleFan, size);
    lines = sf::VertexArray(sf::LineStrip, size);
    float mulsize = 10; 

    try{
        StateColor stateTmp = manager->getStateByID(val["STATEID"].asInt());
        int r = stateTmp.r, b = stateTmp.b, g = stateTmp.g;
        // Load county data
        for(int i = 0; i < size; i++){
            county[i].position = sf::Vector2f((val["POINTS"][i][0].asFloat() * mulsize) + 1000, (val["POINTS"][i][1].asFloat() * -mulsize) + 400);
            county[i].color = sf::Color(r,g,b);
            this->transform.position.x = county[i].position.x;
            this->transform.position.y = county[i].position.y;

            lines[i].position = sf::Vector2f((val["POINTS"][i][0].asFloat() * mulsize) + 1000, (val["POINTS"][i][1].asFloat() * -mulsize) + 400);
            lines[i].color = sf::Color::Black;
        }
        error = false;
    }catch(Json::LogicError& ex){
        // We'll just.. not render it.
        error = true;
        printf("\n\n\n\n%s failed to load county: \n", val["NAME"].asCString());
        // actually fuck it we'll end the game
        exit(-1);
    }
}

void Game::County::highlightColor(){
    for(int i = 0; i < county.getVertexCount(); i++){
        county[i].color = sf::Color::Green;
    }
}

void Game::County::defaultColor(){
    for(int i = 0; i < county.getVertexCount(); i++){
        county[i].color = sf::Color::Red;
    }
}

void Game::County::updateScript(){
    this->script->getUpdateFunc()(this, this->transform);
}

void Game::County::draw(sf::RenderWindow* window){
    if(!error){
        window->draw(county);
        window->draw(lines);
    }
}