#include <iostream>

#include <graphics/renderer.h>
#include <scene.h>
#include <game.h>
#include <gameObjects/boat.h>

int main(int argv, char** args){
	Game::Nunticle* game = new Game::Nunticle();

	Engine::Scene scene("Test");

	Game::Boat* boat = new Game::Boat("../assets/textures/testing/testBoat.jpeg");
	scene.addObject(boat);
	// Create renderer	
	Rendering::Renderer renderer(std::string("Nunticle"), 800, 600, game);
	while(1){
		renderer.update(scene);
	}
	return 0;
}
