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

void Score::DrawScore()
{
	std::string stringScore = std::to_string(m_score);

 	std::string::size_type length = stringScore.size();
	for (std::string::size_type i = 0; i < length; ++i)
	{
		m_renderer->SetAt(GAME_WIDTH - (length - i), 0, stringScore[i], B_CYAN);
	}
}

void Score::AddToScore(int points)
{
	m_score += points;
}

void Score::Reset()
{
	m_score = 0;
}
