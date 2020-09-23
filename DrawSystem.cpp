// header file
#include "DrawSystem.h"
// dependencies
#include "DrawComponent.h"
#include "PhysicComponent.h"
#include "ASCIIRenderer.h"


DrawSystem::DrawSystem(ASCIIRenderer* renderer) 
{
	m_renderer = renderer;
}

DrawComponent* DrawSystem::RequestComponent(PhysicComponent* physic, char sprite)
{
	DrawComponent* newComponent = new DrawComponent(physic, sprite);
	
	Components.push_back(*newComponent);

	return newComponent;
}

void DrawSystem::UpdateComponents()
{
	for (DrawComponent component : Components) {
		m_renderer->SetAt(
			component.Physic->Position.x,
			component.Physic->Position.y,
			component.Sprite,
			0x0E
		);
	}
}
