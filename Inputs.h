#pragma once

class ASCIIRenderer;


class Inputs
{
private:
	bool IsPress(int vkey);

public:
	bool UpPress();
	bool DownPress();
	bool LeftPress();
	bool RightPress();
	bool SpacePress();
	bool EchapPress();
	void DebugInputs(ASCIIRenderer* renderer, int x, int y);
	bool ResetPress();
};
