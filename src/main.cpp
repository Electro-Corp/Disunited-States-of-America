#include <iostream>
#include <math.h>
#include <filesystem>

#include <graphics/renderer.h>
#include <scene.h>
#include <game.h>
#include <gameObjects/boat.h>
#include <gameObjects/map.h>
#include <gameObjects/county.h>


namespace fs = std::filesystem;

int main(int argv, char** args){
	Game::Nunticle* game = new Game::Nunticle();

	Engine::Scene scene("Test");
	
	Game::Boat* boat = new Game::Boat("../assets/textures/testing/boat.png");
	Engine::GameObject* camera = new Engine::GameObject();
	//Game::Map* map = new Game::Map("../assets/textures/testing/earth8.jpg");
	
	game->loadScript(boat, "../assets/scripts/testScript.lua");
	game->loadScript(camera, "../assets/scripts/engine/camera.lua");
	//game->loadScript(map, "../assets/scripts/gameObjs/map.lua");
	
	//scene.addObject(map);
	
	//scene.addObject(boat);
	
	// load all of the US
	for (const auto & entry : fs::directory_iterator("../assets/map_data/counties")){
		//std::cout << "Loading " << entry.path().string() << "\n";
    	Game::County* county = new Game::County(entry.path().string());
		game->loadScript(county, "../assets/scripts/gameObjs/county.lua");
		scene.addObject(county);
    }

	scene.addObject(camera);


	game->initScripts();
	

	while(1){
		game->tick(scene);
	}
	return 0;
}
