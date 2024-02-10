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
	// make a music/audio manager in the future
	sf::Music music;
	if (!music.openFromFile("../assets/music/load.ogg"))
		return -1;
	music.setVolume(0);
	music.play();


	// Load a random quote
	JsonReader tmp("../assets/quotes.json");
    Json::Value val = tmp.read();
	std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(0, val["Quotes"].size() - 1);

	std::string quote = val["Quotes"][distr(generator)].asString();


	Game::DSA* game = new Game::DSA();

	Engine::Scene scene("Test");
	Engine::Scene loading("Loading");

	
	float loadScreens = std::distance(fs::directory_iterator("../assets/textures/loading"), fs::directory_iterator{});

	std::uniform_int_distribution<int> loadDistr(1, loadScreens);

	int fileChoose = loadDistr(generator), g = 1;
	for(int i = 0; i < 50; i++) fileChoose = loadDistr(generator);

	std::cout << loadScreens << " | " << fileChoose << "\n";

	Game::Map* loadBG;

	for (const auto & entry : fs::directory_iterator("../assets/textures/loading")){
		if(g == fileChoose){
			loadBG = new Game::Map(entry.path().string());
			break;
		}
		g++;
	}

	 
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
		if(music.getVolume() < 100) music.setVolume(music.getVolume() + 0.1);
		// Show quotes
		int load = ((count / fileTot) * 100);
		if(load % 20 == 0){
			quote = val["Quotes"][distr(generator)].asString();
			quoteText->setText(quote);
		}

		// Let the user know whats up
		game->changeWindowTitle(std::string{"Disunited States of America | Loading.. " + std::to_string(load) + "% ("+ entry.path().string() +")"});
		loadingText->setText(std::string{"Loading.. " + std::to_string(load) + "%"});
    	
		// Load county
		Game::County* county = new Game::County(entry.path().string());
		game->loadScript(county, "../assets/scripts/gameObjs/county.lua");

		if(load == 50){
			camera->transform.position = county->transform.position;
		}

		scene.addObject(county);
		count++;
		game->tick(loading);
    }

	game->changeWindowTitle("Disunited States of America");

	loadingText->setSize(0);
	quoteText->setSize(0);


	scene.addObject(loadBG);

	scene.addObject(camera);

	game->initScripts();

	camera->updateScript();

	
	printf("trasnform udpated!\n");

	float fadeSpeed = 0.1f;
	// Fade out
	for(float i = 255; i > 0; i -= fadeSpeed * game->getTime()){
		loadBG->transform.position = camera->transform.position;
		loadBG->getSprite()->getSprite()->setColor(sf::Color(255, 255, 255, i));
		game->tick(scene);
	}
	loadBG->getSprite()->getSprite()->setColor(sf::Color(255, 255, 255, 0));
		

	while(1){
		game->tick(scene);
	}
	return 0;
}
