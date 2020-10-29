#include "UIEndText.h"
#include "DrawTextComponent.h"
#include "DrawTextSystem.h"
#include "Score.h"
#include "Inputs.h"
#include "GameWorld.h"
#include "Constants.h"

void UIEndText::Init(GameWorld* world, double startX, double startY, double velX, double velY) 
{
	m_world = world;
	m_gameOverText = m_world->TextDrawer->RequestComponent(
		Vec2<unsigned int>(
			(unsigned int)startX, 
			(unsigned int)startY - 1
		), 
		"GAME OVER", 
		B_CYAN, 
		TextHorzAlign::Center
	);
	m_scoreText = m_world->TextDrawer->RequestComponent(
		Vec2<unsigned int>(
			(unsigned int)startX, 
			(unsigned int)startY + 1
		), 
		"You scored " + std::to_string(m_world->ScoreBoard->GetScore()) + ", Press R to restart",
		B_PRPL, 
		TextHorzAlign::Center
	);
}

void UIEndText::Update(float deltaTime) 
{
	if (m_world->Keyboard->ResetPress()) {
		m_world->Reset();
	}
}

void UIEndText::Delete()
{
	m_world->TextDrawer->DeleteComponent(m_gameOverText);
	m_world->TextDrawer->DeleteComponent(m_scoreText);
}