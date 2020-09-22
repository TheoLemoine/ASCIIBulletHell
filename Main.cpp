#include <iostream>
#include "ASCIIRenderer.h"
#include "GameClock.h"
#include "GameWorld.h"

using namespace std;

const SHORT GAME_WIDTH = 120;
const SHORT GAME_HEIGHT = 60;

int main() {

	// Game loop with delta time
	// Get Input at each frame (and rase events ?)
	// Have Components for ID, rendering, Physics, Collisions, ...

	// game time
	GameClock clock;
	clock.SetMultiplier(GameClock::MULT_SEC);

	// drawing on console
	ASCIIRenderer renderer(GAME_WIDTH, GAME_HEIGHT);

	GameWorld world(&renderer, &clock);
	world.InitWorld();
	world.StartGameLoop();

	return 0;

}