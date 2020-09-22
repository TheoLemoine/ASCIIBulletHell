#include <iostream>
#include "ASCIIRenderer.h"
#include "Keyboard.h"
using namespace std;

int main() {

	ASCIIRenderer renderer(90, 40);
	Keyboard input;
	while (!input.EchapPress())
	{
		if (input.UpPress())
			renderer.SetAt(10, 10, 'U', 0x0E);
		else
			renderer.SetAt(10, 10, ' ', 0x0E);
		if (input.DownPress())
			renderer.SetAt(11, 10, 'D', 0x0E);
		else
			renderer.SetAt(11, 10, ' ', 0x0E);
		if (input.LeftPress())
			renderer.SetAt(12, 10, 'L', 0x0E);
		else
			renderer.SetAt(12, 10, ' ', 0x0E);
		if (input.RightPress())
			renderer.SetAt(13, 10, 'R', 0x0E);
		else
			renderer.SetAt(13, 10, ' ', 0x0E);
		if (input.SpacePress())
			renderer.SetAt(14, 10, 'S', 0x0E);
		else
			renderer.SetAt(14, 10, ' ', 0x0E);

		renderer.Render();
	}

	return 0;

}