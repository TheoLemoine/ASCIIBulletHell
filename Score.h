#pragma once

class ASCIIRenderer;

class Score
{
public:
	Score(ASCIIRenderer* renderer);
	void AddToScore(int points);
	int GetScore();
	void Reset();
private:
	ASCIIRenderer* m_renderer;

	int m_score;
};

