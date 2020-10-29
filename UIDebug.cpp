#include "UIDebug.h"
#include "DrawTextComponent.h"
#include "DrawTextSystem.h"
#include "GameWorld.h"
#include "Constants.h"


void UIDebug::Init(GameWorld* world, double startX, double startY, double velX, double velY) {
	m_world = world;

	m_fpsDrawer = m_world->TextDrawer->RequestComponent(Vec2<unsigned int>(GAME_WIDTH, GAME_HEIGHT - 1), "", B_CYAN, TextHorzAlign::Right);
}

void UIDebug::Update(float deltaTime) {
	if (deltaTime > 0.f) {
		m_fpsDrawer->m_content = std::to_string((int)(1 / deltaTime)) + " FPS";
	}
}

void UIDebug::Delete() {
	m_world->TextDrawer->DeleteComponent(m_fpsDrawer);
}