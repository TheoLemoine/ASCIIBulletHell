#include "ASCIIRenderer.h"
#include "GameClock.h"
#include "GameWorld.h"
#include "Keyboard.h"
#include "Starship.h"

const SHORT GAME_WIDTH = 120;
const SHORT GAME_HEIGHT = 60;

int main() {

	// Have Components for ID, rendering, Physics, Collisions, ...
	
	// game time
	GameClock clock;
	clock.SetMultiplier(GameClock::MULT_SEC);

	// drawing on console
	ASCIIRenderer renderer(GAME_WIDTH, GAME_HEIGHT);

	// inputs
	Keyboard keyboard;

	GameWorld world(&renderer, &clock, &keyboard);
	world.InitWorld();
	world.StartGameLoop();

	return 0;

}