#pragma once
#include <WinUser.h>
#define VK_KEY_D	0x44                //('D')	D
#define VK_KEY_Q	0x51                //('Q')	Q
#define VK_KEY_S	0x53                //('S')	S
#define VK_KEY_Z	0x5A                //('Z')	Z

class Keyboard
{
private:
	bool IsPress(int vkey)
	{
		return GetAsyncKeyState(vkey);
	}

public:
	bool UpPress()
	{
		return IsPress(VK_KEY_Z) || IsPress(VK_UP);
	}

	bool DownPress()
	{
		return IsPress(VK_KEY_S) || IsPress(VK_DOWN);
	}

	bool LeftPress()
	{
		return IsPress(VK_KEY_Q) || IsPress(VK_LEFT);
	}

	bool RightPress()
	{
		return IsPress(VK_KEY_D) || IsPress(VK_RIGHT);
	}

	bool SpacePress()
	{
		return IsPress(VK_SPACE);
	}

	bool EchapPress()
	{
		return IsPress(VK_ESCAPE);
	}

	void DebugKeyboard(ASCIIRenderer* renderer, int x, int y)
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
};
