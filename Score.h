#pragma once

class ASCIIRenderer;

class Score
{
public:
	Score(ASCIIRenderer* renderer);
	void DrawScore();
	void AddToScore(int points);
	void Reset();
private:
	ASCIIRenderer* m_renderer;

	int m_score;
};

