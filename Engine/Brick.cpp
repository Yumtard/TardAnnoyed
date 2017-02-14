#include "Brick.h"

Brick::Brick(RectF& Rect, const Color& c)
	:
	rect(Rect),
	color(c)
{}

bool Brick::DoBallCollision(Ball& ball)
{
	if (!destroyed && rect.IsOverlapping(ball.GetRect()))
	{
		destroyed = true;
		ball.ReboundY();
		return true;
	}
	return false;
}

void Brick::Draw(Graphics& gfx) const
{
	if (!destroyed)
	{
		gfx.DrawRect(rect.GetExpanded(- padding), color);
	}
}
