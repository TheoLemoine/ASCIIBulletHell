#pragma once

class ASCIIRenderer;

class Score
{
public:
	Score(ASCIIRenderer* renderer);
	void DrawScore();
	void AddToScore(int points);

private:
	ASCIIRenderer* m_renderer;

	int m_score;
};

