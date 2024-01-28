#include <iostream>
#include <math.h>

#include <graphics/renderer.h>
#include <scene.h>
#include <game.h>
#include <gameObjects/boat.h>

int main(int argv, char** args){
	Game::Nunticle* game = new Game::Nunticle();

	Engine::Scene scene("Test");

	Game::Boat* boat = new Game::Boat("../assets/textures/testing/boat.png");
	game->loadScript(boat, "../assets/scripts/testScript.lua");
	scene.addObject(boat);
	// Create renderer	

	game->initScripts();
	
	while(1){

		game->tick(scene);
		
	}
	return 0;
}
