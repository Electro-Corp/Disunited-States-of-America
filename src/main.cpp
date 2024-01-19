#include <iostream>

#include <game.h>
#include <graphics/renderer.h>

int main(int argv, char** args){
	Game::Nunticle* game = new Game::Nunticle();
	// Create renderer
	Rendering::Renderer renderer(std::string("Nunticle"), 800, 600, game);
	while(1){
		renderer.update();
	}
	return 0;
}
