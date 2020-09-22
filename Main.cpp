#include <iostream>
#include "ASCIIRenderer.h"
#include "Starship.h"
using namespace std;

int main() {

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

	return 0;

}