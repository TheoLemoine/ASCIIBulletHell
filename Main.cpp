#include <iostream>
#include "ASCIIRenderer.h"
#include "Keyboard.h"
using namespace std;

int main() {

	ASCIIRenderer renderer(90, 40);
	Keyboard input;
	while (!input.EchapPress())
	{
		input.DebugKeyboard(&renderer, 0, 1);

		renderer.Render();
	}

	return 0;

}