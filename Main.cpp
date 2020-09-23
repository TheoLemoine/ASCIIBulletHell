// dependencies
#include "Constants.h"
#include "GameWorld.h"
#include "ASCIIRenderer.h"
#include "GameClock.h"
#include "Inputs.h"
#include "Starship.h"

int main() {

	// Have Components for ID, rendering, Physics, Collisions, ...
	
	// game time
	GameClock clock;
	clock.SetMultiplier(GameClock::MULT_SEC);

	// drawing on console
	ASCIIRenderer renderer(GAME_WIDTH, GAME_HEIGHT);

	// inputs
	Inputs keyboard;

	// create and start game
	GameWorld world(&renderer, &clock, &keyboard);
	world.InitWorld();
	world.StartGameLoop();

	return 0;

}