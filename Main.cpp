#include <iostream>
#include "ASCIIRenderer.h"
#include "GameClock.h"
#include "GameWorld.h"

#include "Starship.h"
using namespace std;

const SHORT GAME_WIDTH = 120;
const SHORT GAME_HEIGHT = 60;

int main() {

	// Game loop with delta time
	// Get Input at each frame (and rase events ?)
	// Have Components for ID, rendering, Physics, Collisions, ...
	ASCIIRenderer renderer(90, 40);
	Keyboard input;
	Starship player;
	player.physic = new Physic(25, 25);
	while (!input.EchapPress())
	{
		input.DebugKeyboard(&renderer, 0, 1);

		player.Update(&input,0.1f);

		renderer.Render();
	}
	delete player.physic;
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