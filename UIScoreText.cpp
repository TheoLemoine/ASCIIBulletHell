#include "UIScoreText.h"
#include "DrawTextComponent.h"
#include "DrawTextSystem.h"
#include "Score.h"
#include "GameWorld.h"
#include "Constants.h"

void UIScoreText::Init(GameWorld* world, double startX, double startY, double velX, double velY)
{
	m_world = world;
	m_scoreText = m_world->TextDrawer->RequestComponent(
		Vec2<unsigned int>(GAME_WIDTH, 0),
		"0", B_CYAN,
		TextHorzAlign::Right
	);
}

void UIScoreText::Update(float deltaTime)
{
	m_scoreText->m_content = std::to_string(m_world->ScoreBoard->GetScore()) + " Pts";
}

void UIScoreText::Delete()
{
	m_world->TextDrawer->DeleteComponent(m_scoreText);
}