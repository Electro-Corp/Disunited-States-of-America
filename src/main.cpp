#include <iostream>
#include <math.h>

#include <graphics/renderer.h>
#include <scene.h>
#include <game.h>
#include <gameObjects/boat.h>

int main(int argv, char** args){
	Game::Nunticle* game = new Game::Nunticle();

	Engine::Scene scene("Test");

	Game::Boat* boat = new Game::Boat("../assets/textures/testing/testBoat.jpeg");
	game->loadScript(boat, "../assets/scripts");
	scene.addObject(boat);
	// Create renderer	
	Rendering::Renderer renderer(std::string("Nunticle"), 800, 600, game);
	float i = 0;
	while(1){
		// Test transformations
		i += 0.001f;
		boat->transform.position.x = abs(sin(i) * 700);
		boat->transform.position.y = abs(sin(i) * 500);

		// Update the render
		renderer.update(scene);
		
	}
	return 0;
}
