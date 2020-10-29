#pragma once
#include "Vec2.h"
#include "Constants.h"
#include <Windows.h>
#include <string>


struct DrawTextComponent
{
public:
	
	DrawTextComponent(Vec2<unsigned int> coords, std::string content, WORD color, TextHorzAlign align = TextHorzAlign::Left);

	TextHorzAlign m_align;
	Vec2<unsigned int> m_coords;
	WORD m_color;
	std::string m_content;

};

