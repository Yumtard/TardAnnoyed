#include "Lives.h"

Lives::Lives(Vec2 & pos_in)
	:
	position(pos_in)
{
	for (int i = 0; i < nLivesMax; ++i)
	{
		pos[i] = position;
		position.x += 30;
	}
}

void Lives::Decrease()
{
	nLives--;
}

void Lives::Draw(Graphics& gfx)
{
	for (int i = 0; i < nLives; ++i)
	{
		SpriteCodex::DrawBall(pos[i], gfx);
	}
}

bool Lives::LivesLeft()
{
	return nLives > 0;
}

void Lives::Reset()
{
	nLives = 3;
}
