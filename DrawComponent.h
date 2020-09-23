#pragma once

struct PhysicComponent;

struct DrawComponent
{
public:
	DrawComponent(PhysicComponent* physic, char sprite);
	PhysicComponent* Physic;
	char Sprite;

};

