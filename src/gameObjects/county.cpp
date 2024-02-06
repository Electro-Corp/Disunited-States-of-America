#include <gameObjects/county.h>


Game::County::County(std::string filename) : Engine::GameObject(){
    drawable = false;
    JsonReader tmp(filename);
    Json::Value val = tmp.read();
    county = sf::VertexArray(sf::LineStrip, val["POINTS"].size());
    try{
        for(int i = 0; i < val["POINTS"].size(); i++){
            Game::CountyAreaPoint temp = Game::CountyAreaPoint();
            temp.x = val["POINTS"][i][0].asFloat() * 10;
            temp.y = val["POINTS"][i][1].asFloat() * -10;
            /*std::cout << temp.x << "\n";
            std::cout << temp.y << "\n";*/
            county[i].position = sf::Vector2f(temp.x, temp.y);
            county[i].color = sf::Color::Red;
        }
        error = false;
    }catch(Json::LogicError& ex){
        error = true;
        printf("%s failed to load.\n", val["NAME"].asCString());
    }
}

void Game::County::draw(sf::RenderWindow* window){
    if(!error)
        window->draw(county);
}