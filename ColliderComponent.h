#pragma once
#include "Constants.h"
#include <stdio.h>

struct PhysicComponent;
struct ColliderComponent;


//[event_source(native)]
struct ColliderComponent
{
public:
	PhysicComponent* Physic;
	double Size;
	Tag ComponentTag;
	ColliderComponent(PhysicComponent* physics, double size, Tag tag);
	__event void OnCollision(ColliderComponent* other);
};

