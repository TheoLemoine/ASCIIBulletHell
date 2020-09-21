#pragma once
#include <Windows.h>

class ASCIIRenderer
{

public:

	ASCIIRenderer(SHORT width, SHORT height) {

		// get size of the user screen
		RECT desktop;
		const HWND hwndDesktop = GetDesktopWindow();
		GetWindowRect(hwndDesktop, &desktop);

		// get size of window console
		RECT console;
		HWND hwndConsole = GetConsoleWindow();
		GetWindowRect(hwndConsole, &console);

		// set window style
		SetWindowLongPtr(hwndConsole, GWL_STYLE, WS_BORDER | WS_VISIBLE);

		// get std handle and console buffer
		m_hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
		m_dwBufferSize = { width, height };
		m_dwBufferCoord = { 0, 0 };
		m_rcRegion = { 0, 0, width - 1, height - 1 };

		SetConsoleWindowInfo(m_hOutput, true, &m_rcRegion);
		SetConsoleScreenBufferSize(m_hOutput, m_dwBufferSize);

		// 1D array, use width to get item at specific row.
		m_buffer = new CHAR_INFO[m_dwBufferSize.X * m_dwBufferSize.Y];

		// Initialize buffer
		ReadConsoleOutput(m_hOutput, m_buffer, m_dwBufferSize, m_dwBufferCoord, &m_rcRegion);

		// center console in desktop
		SetWindowPos(hwndConsole, HWND_TOPMOST, desktop.right / 2 - console.right / 2, desktop.bottom / 2 - console.bottom / 2, 0, 0, SWP_NOSIZE);

	}

	~ASCIIRenderer() {
		delete[] m_buffer;
	}

	void Render() {

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

