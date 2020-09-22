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
};
