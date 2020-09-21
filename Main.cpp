#include <iostream>
#include "ASCIIRenderer.h"

using namespace std;

int main() {

	ASCIIRenderer renderer(80, 40);
	while (true)
	{
		renderer.Render();
	}

	return 0;
}