#include "Brick.h"

Brick::Brick(Vec2 & pos_in, float width_in, float height_in)
	:
	pos(pos_in),
	width(width_in),
	height(height_in)
{}

void Brick::DoBallCollision(Ball& ball)
{
	RectF rect(GetRect());
	if (rect.IsOverlapping(ball.GetRect()))
	{
		destroyed = true;
		ball.ReboundY();
	}
}

void Brick::Draw(Graphics& gfx) const
{
	if (!destroyed)
	{
		gfx.DrawRect(GetRect(), color);
	}
	
}

void Brick::Update(Ball & ball)
{
	if (!destroyed)
	{
		DoBallCollision(ball);
	}
}

RectF Brick::GetRect() const
{
	return RectF(pos.x, pos.x + width, pos.y, pos.y + height );
}
