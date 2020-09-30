#include "GameWorld.h"
#include "GameClock.h"
#include "Inputs.h"
#include "Score.h"
#include "ASCIIRenderer.h"
#include "Constants.h"

int main() {
	
	// game time
	GameClock clock;
	clock.SetMultiplier(GameClock::MULT_SEC);

	// drawing on console
	ASCIIRenderer renderer(GAME_WIDTH, GAME_HEIGHT);

	// inputs
	Inputs keyboard;

	// scoring
	Score scoreBoard(&renderer);

	// create and start game
	GameWorld world(&renderer, &clock, &keyboard, &scoreBoard);
	world.InitWorld();
	world.StartGameLoop();

	return 0;
}