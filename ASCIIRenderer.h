#pragma once
#include <Windows.h>
#include <stdio.h>

class ASCIIRenderer
{

public:
	ASCIIRenderer(SHORT width, SHORT height) {

		m_hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

		m_dwBufferSize = { width, height };
		m_dwBufferCoord = { 0, 0 };
		m_rcRegion = { 0, 0, width - 1, height - 1 };

		SetConsoleWindowInfo(m_hOutput, true, &m_rcRegion);
		SetConsoleScreenBufferSize(m_hOutput, m_dwBufferSize);

		// 1D array, use width to get item at specific row.
		m_buffer = new CHAR_INFO[m_dwBufferSize.X * m_dwBufferSize.Y];
	}

	~ASCIIRenderer() {
		delete[] m_buffer;
	}

	void Render() {

		ReadConsoleOutput(m_hOutput, m_buffer, m_dwBufferSize, m_dwBufferCoord, &m_rcRegion);

		SetAt(0, 0, 'H', 0x0E);
		SetAt(0, m_dwBufferSize.Y - 1, 'H', 0x0E);
		SetAt(m_dwBufferSize.X - 1, 0, 'H', 0x0E);
		SetAt(m_dwBufferSize.X - 1, m_dwBufferSize.Y - 1, 'H', 0x0E);

		SetAt(5, 10, 'H', 0x0E);
		SetAt(5, 11, 'i', 0x0B);
		SetAt(5, 12, '!', 0x0A);

		WriteConsoleOutput(m_hOutput, m_buffer, m_dwBufferSize, m_dwBufferCoord, &m_rcRegion);
	}

	CHAR_INFO* GetAt(int x, int y) {
		return &m_buffer[y * m_dwBufferSize.X + x];
	}

	void SetAt(int x, int y, CHAR AsciiChar, WORD Attributes) {
		CHAR_INFO* info = GetAt(x, y);
		info->Char.AsciiChar = AsciiChar;
		info->Attributes = Attributes;
	}

private:
	HANDLE m_hOutput;
	COORD m_dwBufferSize;
	COORD m_dwBufferCoord;
	SMALL_RECT m_rcRegion;
	CHAR_INFO* m_buffer;
};

