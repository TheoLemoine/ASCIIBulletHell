// header file
#include "DrawComponent.h"
// dependencies
#include "PhysicComponent.h"

DrawComponent::DrawComponent(PhysicComponent* physic, char sprite) {
	Sprite = sprite;
	Physic = physic;
}
