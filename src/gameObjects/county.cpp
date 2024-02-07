#include <gameObjects/county.h>


Game::County::County(std::string filename) : Engine::GameObject(){
    drawable = false;
    JsonReader tmp(filename);
    Json::Value val = tmp.read();
    county = sf::VertexArray(sf::TriangleFan, val["POINTS"].size());
    lines = sf::VertexArray(sf::LineStrip, val["POINTS"].size());
    float mulsize = 10; 

    const int range_from = 0;
    const int range_to = 255;
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(range_from, range_to);

    int r = distr(generator), g = distr(generator), b = distr(generator);
    try{
        // Load county data
        for(int i = 0; i < val["POINTS"].size(); i++){
            county[i].position = sf::Vector2f(val["POINTS"][i][0].asFloat() * mulsize, val["POINTS"][i][1].asFloat() * -mulsize);
            county[i].color = sf::Color(r,g,b);

            lines[i].position = sf::Vector2f(val["POINTS"][i][0].asFloat() * mulsize, val["POINTS"][i][1].asFloat() * -mulsize);
            lines[i].color = sf::Color(g,b,r);
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

void Game::County::draw(sf::RenderWindow* window){
    if(!error){
        window->draw(county);
        window->draw(lines);
    }
}