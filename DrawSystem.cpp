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

DrawComponent* DrawSystem::RequestComponent(
	PhysicComponent* physic,
	std::vector<std::vector<char>> charMaps,
	std::vector<std::vector<int>> colorMaps,
	int width, int height, float period
) {
	DrawComponent* newComponent = new DrawComponent(physic, charMaps, colorMaps, width, height, period);
	
	Components.push_back(newComponent);

	return newComponent;
}

void DrawSystem::UpdateComponents(float deltaTime)
{
	for (DrawComponent* component : Components) {
		
		auto& charFrame = component->CharMaps[component->currentFrame];
		auto& colorFrame = component->ColorMaps[component->currentFrame];
		for (int i = 0; i < charFrame.size(); i++)
		{
			// get character placement and center it
			int x = i % component->Width - component->Width / 2;
			int y = i / component->Width - component->Height / 2;

			// place on the map
			x += static_cast<int>(component->Physic->Position.x);
			y += static_cast<int>(component->Physic->Position.y);

			m_renderer->SetAt(x, y, charFrame[i], colorFrame[i]);
		}

		// Could do better
		component->frameTime += deltaTime;
		if (component->frameTime > component->framePeriod) {
			component->currentFrame++;
			component->frameTime -= component->framePeriod;
			if (component->currentFrame >= component->CharMaps.size()) component->currentFrame = 0;
		}
		
	}
}
