#include "DrawTextComponent.h"
#include "Constants.h"
#include <string>
#include <Windows.h>


DrawTextComponent::DrawTextComponent(
	Vec2<unsigned int> coords, 
	std::string content,
	WORD color,
	TextHorzAlign align) 
{

	m_coords = coords;
	m_content = content;
	m_color = color;
	m_align = align;

}