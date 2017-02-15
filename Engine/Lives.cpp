#include "Lives.h"

Lives::Lives(Vec2 & pos_in)
	:
	pos(pos_in)
{}

void Lives::Decrease()
{
	nLives--;
}

void Lives::Draw(Graphics& gfx)
{
	for (int i = 0; i < nLives; ++i)
	{
		SpriteCodex::DrawBall(pos, gfx);
		pos.x += 30;
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
