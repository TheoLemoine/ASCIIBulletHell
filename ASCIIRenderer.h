#pragma once
#include <Windows.h>


class ASCIIRenderer
{

public:

	ASCIIRenderer(SHORT width, SHORT height);

	~ASCIIRenderer();

	void Render();
	void Clear();

	CHAR_INFO* GetAt(int x, int y);

	void SetAt(int x, int y, CHAR AsciiChar, WORD Attributes);

private:
	HANDLE m_hOutput;
	COORD m_dwBufferSize;
	COORD m_dwBufferCoord;
	SMALL_RECT m_rcRegion;
	CHAR_INFO* m_buffer;
};

