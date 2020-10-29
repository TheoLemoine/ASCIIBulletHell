#pragma once
#include "Vec2.h"
#include "Constants.h"
#include <vector>
#include <string>
#include <Windows.h>

class ASCIIRenderer;
struct DrawTextComponent;


class DrawTextSystem
{

public:
	DrawTextSystem(ASCIIRenderer* renderer);

	std::vector<DrawTextComponent*> Components;

	DrawTextComponent* RequestComponent(Vec2<unsigned int> coords, std::string content, WORD color, TextHorzAlign align = TextHorzAlign::Left);
	void DeleteComponent(DrawTextComponent* componentPointer);
	void UpdateComponents();

private:
	ASCIIRenderer* m_renderer;

};

