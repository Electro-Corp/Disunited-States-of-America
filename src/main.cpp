/**
 * Temporary main.cpp
 * 
 * its not very good and exists only for testing
*/


#include <iostream>
#include <math.h>
#include <filesystem>
#include <SFML/Audio.hpp>

#include <graphics/renderer.h>
#include <scene.h>
#include <game.h>
#include <gameObjects/boat.h>
#include <gameObjects/map.h>
#include <gameObjects/county.h>
#include <gameObjects/ui/text.h>


namespace fs = std::filesystem;

int main(int argv, char** args){
	sf::Music music;
	if (!music.openFromFile("../assets/music/load.ogg"))
		return -1;
	music.play();

	// Load a random quote
	JsonReader tmp("../assets/quotes.json");
    Json::Value val = tmp.read();
	std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(0, val["Quotes"].size() - 1);

	std::string quote = val["Quotes"][distr(generator)].asString();

	std::cout << quote;



	Game::Nunticle* game = new Game::Nunticle();

	Engine::Scene scene("Test");
	Engine::Scene loading("Loading");

	Game::Map* loadBG = new Game::Map("../assets/textures/loading/load1.png");
	game->loadScript(loadBG, "../assets/scripts/gameObjs/background.lua");
	loading.addObject(loadBG);

	UI::Text* loadingText = new UI::Text("Loading..");
	game->loadScript(loadingText, "../assets/scripts/gameObjs/loadingText.lua");
	loading.addObject(loadingText);

	UI::Text* quoteText = new UI::Text(quote);
	game->loadScript(quoteText, "../assets/scripts/gameObjs/quoteText.lua");
	loading.addObject(quoteText);


	
	
	Game::Boat* boat = new Game::Boat("../assets/textures/testing/boat.png");
	Engine::GameObject* camera = new Engine::GameObject();
	//Game::Map* map = new Game::Map("../assets/textures/testing/earth8.jpg");
	
	game->loadScript(boat, "../assets/scripts/testScript.lua");
	game->loadScript(camera, "../assets/scripts/engine/camera.lua");
	//game->loadScript(map, "../assets/scripts/gameObjs/map.lua");
	
	//scene.addObject(map);
	
	//scene.addObject(boat);
	
	float fileTot = std::distance(fs::directory_iterator("../assets/map_data/counties"), fs::directory_iterator{});
	float count = 0;
	// load all of the US
	for (const auto & entry : fs::directory_iterator("../assets/map_data/counties")){
		int load = (int)((count / fileTot) * 100);
		if(load % 20 == 0){
			quote = val["Quotes"][distr(generator)].asString();
			quoteText->setText(quote);
		}

		
		//std::cout << "Percent Loaded: " << load << "\r";
		game->changeWindowTitle(std::string{"Disunited States of America | Loading.. " + std::to_string(load) + "% ("+ entry.path().string() +")"});
		loadingText->setText(std::string{"Loading.. " + std::to_string(load) + "%"});
		//std::cout << "Loading " << entry.path().string() << "\n";
    	Game::County* county = new Game::County(entry.path().string());
		game->loadScript(county, "../assets/scripts/gameObjs/county.lua");
		scene.addObject(county);
		count++;
		game->tick(loading);
    }

	game->changeWindowTitle("Disunited States of America");

	scene.addObject(camera);


	game->initScripts();
	

	while(1){
		game->tick(scene);
	}
	return 0;
}
