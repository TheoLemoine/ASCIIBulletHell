#include "DrawTextComponent.h"
#include "DrawTextSystem.h"
#include "ASCIIRenderer.h"
#include <Windows.h>


DrawTextSystem::DrawTextSystem(ASCIIRenderer* renderer) 
{
	m_renderer = renderer;
}

DrawTextComponent* DrawTextSystem::RequestComponent(Vec2<unsigned int> coords, std::string content, WORD color, TextHorzAlign align) 
{
	auto newComponent = new DrawTextComponent(coords, content, color, align);

	Components.push_back(newComponent);
	return newComponent;
}

void DrawTextSystem::DeleteComponent(DrawTextComponent* componentPointer) 
{
	auto end_itr = Components.end();
	for (auto itr = Components.begin(); itr != end_itr; ++itr)
	{
		if (*itr == componentPointer) {
			Components.erase(itr);
			break;
		}
	}

	delete componentPointer;
}

void DrawTextSystem::UpdateComponents() 
{
	for (auto component : Components) 
	{
		int length = component->m_content.size();
		int offset;

		switch (component->m_align)
		{
			case TextHorzAlign::Left:
				offset = 0;
				break;
			case TextHorzAlign::Center:
				offset = -(length/2);
				break;
			case TextHorzAlign::Right:
			default:
				offset = -(length);
				break;
		}

		for (int i = 0; i < length; ++i)
		{
			m_renderer->SetAt(component->m_coords.x + offset + i, component->m_coords.y, component->m_content[i], component->m_color);
		}
	}
}