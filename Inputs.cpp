// header file
#include "Inputs.h"

#include "ASCIIRenderer.h"
#include <WinUser.h>
#include <iostream>

constexpr int VK_KEY_D = 0x44;
constexpr int VK_KEY_Q = 0x51;
constexpr int VK_KEY_S = 0x53;
constexpr int VK_KEY_Z = 0x5A;
constexpr int VK_KEY_R = 0x52;


bool Inputs::IsPress(int vkey)
{
	return GetAsyncKeyState(vkey);
}

bool Inputs::GetGamepadState()
{
	return (XInputGetState(0, &state) == ERROR_SUCCESS);
}

Inputs::Inputs()
{
	controllerId = -1;

	for (DWORD i = 0; i < XUSER_MAX_COUNT; i++)
	{
		ZeroMemory(&state, sizeof(XINPUT_STATE));

		if (XInputGetState(i, &state) == ERROR_SUCCESS)
		{
			controllerId = i;
			break;
		}
	}
	//std::cout << controllerId << "/" << XUSER_MAX_COUNT << std::endl;
}

float Inputs::UpPress()
{
	//KEYBOARD
	float value = IsPress(VK_KEY_Z) || IsPress(VK_UP) ? 1 : 0;
	//GAMEPAD
	if (controllerId >= 0)
	{
		value = fmaxf(controllerId, (float)state.Gamepad.sThumbLY / 32767);
		//std::cout << "joy : " << value << std::endl;

	}

	return value;
}

float Inputs::DownPress()
{
	float value = IsPress(VK_KEY_S) || IsPress(VK_DOWN) ? 1 : 0;
	
	//GAMEPAD
	if (controllerId >= 0)
	{
		value = -1.0*fminf(controllerId, (float)state.Gamepad.sThumbLY / 32767);
		//std::cout << "joy : " << value << std::endl;

	}
	return value;
}

float Inputs::LeftPress()
{
	float value = IsPress(VK_KEY_Q) || IsPress(VK_LEFT) ? 1 : 0;

	//GAMEPAD
	if (controllerId >= 0)
	{
		value = -1.0 * fminf(controllerId, (float)state.Gamepad.sThumbLY / 32767);
		//std::cout << "joy : " << value << std::endl;

	}
	return value;
}

float Inputs::RightPress()
{
	float value = IsPress(VK_KEY_D) || IsPress(VK_RIGHT) ? 1 : 0;

	//GAMEPAD
	if (controllerId >= 0)
	{
		value = -1.0 * fminf(controllerId, (float)state.Gamepad.sThumbLY / 32767);
		//std::cout << "joy : " << value << std::endl;
	}
	return value;
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

bool Inputs::ResetPress()
{
	return IsPress(VK_KEY_R);
}
