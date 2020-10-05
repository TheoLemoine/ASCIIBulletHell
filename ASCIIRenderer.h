#pragma once
#include <Windows.h>
#include <string>


class ASCIIRenderer
{

public:

	ASCIIRenderer(SHORT width, SHORT height);

	~ASCIIRenderer();

	void Render(float deltaTime);
	void Clear();

	CHAR_INFO* GetAt(int x, int y);

	void SetAt(int x, int y, CHAR AsciiChar, WORD Attributes);

	void SetAt(int x, int y, std::string AsciiString, WORD Attributes);

private:
	HANDLE m_hOutput;
	COORD m_dwBufferSize;
	COORD m_dwBufferCoord;
	SMALL_RECT m_rcRegion;
	CHAR_INFO* m_buffer;
};

