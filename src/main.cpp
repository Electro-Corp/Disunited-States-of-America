#include <iostream>

#include <graphics/renderer.h>
#include <game.h>

int main(int argv, char** args){
	Game::Nunticle game;
	// Create renderer
	Rendering::Renderer renderer("Nunticle", 800, 600, &game);
	while(1){
		renderer.update();
	}
	return 0;
}
