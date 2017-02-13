#include "Brick.h"

Brick::Brick(Vec2 & pos_in, float width_in, float height_in, const Color& c)
	:
	pos(pos_in),
	width(width_in),
	height(height_in),
	color(c)
{}

bool Brick::DoBallCollision(Ball& ball)
{
	RectF rect(GetRect());
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
		RectF rect(GetRect());
		gfx.DrawRect(rect.GetExpanded(- padding), color);
	}
}

RectF Brick::GetRect() const
{
	return RectF(pos.x, pos.x + width, pos.y, pos.y + height );
}

