// header file
#include "Score.h"

#include "ASCIIRenderer.h"
#include "Constants.h"
#include <string>


Score::Score(ASCIIRenderer* renderer)
{
	m_renderer = renderer;
	m_score = 0;
}

void Score::AddToScore(int points)
{
	m_score += points;
}

int Score::GetScore() 
{
	return m_score;
}

void Score::Reset()
{
	m_score = 0;
}
