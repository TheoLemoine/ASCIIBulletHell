#pragma once

class ASCIIRenderer;

#include <Windows.h>
#include <Xinput.h>
#pragma comment (lib, "xinput.lib")

class Inputs
{
private:
	bool IsPress(int vkey);
	bool GetGamepadState();
	XINPUT_STATE state;
	int controllerId;
public:
	Inputs();
	float UpPress();
	float DownPress();
	float LeftPress();
	float RightPress();
	bool SpacePress();
	bool EchapPress();
	void DebugInputs(ASCIIRenderer* renderer, int x, int y);
	bool ResetPress();
};
