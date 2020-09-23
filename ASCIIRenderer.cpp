// header file
#include "ASCIIRenderer.h"
// dependencies
#include "Constants.h"
// external dependencies
#include <Windows.h>


ASCIIRenderer::ASCIIRenderer(SHORT width, SHORT height) {

	// get the user screen
	HWND hwndDesktop = GetDesktopWindow();
	// get console window
	HWND hwndConsole = GetConsoleWindow();
	// set window style
	SetWindowLongPtr(hwndConsole, GWL_STYLE, WS_BORDER | WS_VISIBLE);

	// get std handle and console buffer
	m_hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
	m_dwBufferSize = { width, height };
	m_dwBufferCoord = { 0, 0 };
	m_rcRegion = { 0, 0, width - 1, height - 1 };

	// set font style
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 6;
	cfi.dwFontSize.Y = 12;
	cfi.FontWeight = FW_BOLD;
	SetCurrentConsoleFontEx(m_hOutput, false, &cfi);

	SetConsoleWindowInfo(m_hOutput, true, &m_rcRegion);
	SetConsoleScreenBufferSize(m_hOutput, m_dwBufferSize);

	// 1D array, use width to get item at specific row.
	m_buffer = new CHAR_INFO[m_dwBufferSize.X * m_dwBufferSize.Y];

	// Initialize buffer
	ReadConsoleOutput(m_hOutput, m_buffer, m_dwBufferSize, m_dwBufferCoord, &m_rcRegion);

	// center console in desktop
	RECT desktop;
	GetWindowRect(hwndDesktop, &desktop);

	RECT console;
	GetWindowRect(hwndConsole, &console);

	SetWindowPos(hwndConsole, HWND_TOP,
		desktop.right / 2 - console.right / 2, // center width
		desktop.bottom / 2 - console.bottom / 2, // center height
		0, 0, SWP_NOSIZE);

}

ASCIIRenderer::~ASCIIRenderer() {
	delete[] m_buffer;
}

void ASCIIRenderer::Render() {

	SetAt(0, 0, 'H', 0x0E);
	SetAt(0, m_dwBufferSize.Y - 1, 'H', 0x0E);
	SetAt(m_dwBufferSize.X - 1, 0, 'H', 0x0E);
	SetAt(m_dwBufferSize.X - 1, m_dwBufferSize.Y - 1, 'H', 0x0E);

	WriteConsoleOutput(m_hOutput, m_buffer, m_dwBufferSize, m_dwBufferCoord, &m_rcRegion);
}

CHAR_INFO* ASCIIRenderer::GetAt(int x, int y) {
	y = (y + GAME_HEIGHT) % GAME_HEIGHT;
	x = (x + GAME_WIDTH) % GAME_WIDTH;
	return &m_buffer[y * m_dwBufferSize.X + x];
}

void ASCIIRenderer::SetAt(int x, int y, CHAR AsciiChar, WORD Attributes) {
	if (x < 0 || x >= GAME_WIDTH) return;

	CHAR_INFO* info = GetAt(x, y);
	info->Char.AsciiChar = AsciiChar;
	info->Attributes = Attributes;
}

