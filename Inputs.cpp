// header file
#include "Inputs.h"

#include "ASCIIRenderer.h"
#include <WinUser.h>

constexpr int VK_KEY_D = 0x44;
constexpr int VK_KEY_Q = 0x51;
constexpr int VK_KEY_S = 0x53;
constexpr int VK_KEY_Z = 0x5A;


bool Inputs::IsPress(int vkey)
{
	return GetAsyncKeyState(vkey);
}

bool Inputs::UpPress()
{
	return IsPress(VK_KEY_Z) || IsPress(VK_UP);
}

bool Inputs::DownPress()
{
	return IsPress(VK_KEY_S) || IsPress(VK_DOWN);
}

bool Inputs::LeftPress()
{
	return IsPress(VK_KEY_Q) || IsPress(VK_LEFT);
}

bool Inputs::RightPress()
{
	return IsPress(VK_KEY_D) || IsPress(VK_RIGHT);
}

bool Inputs::SpacePress()
{
	return IsPress(VK_SPACE);
}

bool Inputs::EchapPress()
{
	return IsPress(VK_ESCAPE);
}

void Inputs::DebugInputs(ASCIIRenderer* renderer, int x, int y)
{
	if (UpPress())
		renderer->SetAt(x, y, 'U', 0x0E);
	else
		renderer->SetAt(x, y, ' ', 0x0E);
	if (DownPress())
		renderer->SetAt(x + 1, y, 'D', 0x0E);
	else
		renderer->SetAt(x + 1, y, ' ', 0x0E);
	if (LeftPress())
		renderer->SetAt(x + 2, y, 'L', 0x0E);
	else
		renderer->SetAt(x + 2, y, ' ', 0x0E);
	if (RightPress())
		renderer->SetAt(x + 3, y, 'R', 0x0E);
	else
		renderer->SetAt(x + 3, y, ' ', 0x0E);
	if (SpacePress())
		renderer->SetAt(x + 4, y, 'S', 0x0E);
	else
		renderer->SetAt(x + 4, y, ' ', 0x0E);
}
