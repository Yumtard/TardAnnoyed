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
		if (ball.GetPos().x > rect.left && ball.GetPos().x < rect.right)
		{
			ball.ReboundY();
		}
		else
		{
			ball.ReboundX();
		}

		destroyed = true;		
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

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}
