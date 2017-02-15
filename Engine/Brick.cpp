#include "Brick.h"
#include <assert.h>

Brick::Brick(RectF& Rect, const Color& c)
	:
	rect(Rect),
	color(c)
{}

bool Brick::CheckBallCollision(const Ball & ball) const
{
	return !destroyed && rect.IsOverlapping(ball.GetRect());
}
void Brick::ExecuteBallCollision(Ball& ball)
{
	assert(CheckBallCollision(ball));
	const Vec2 ballPos = ball.GetPos();
	if (std::signbit(ball.GetVel().x) == std::signbit(ballPos.x - rect.GetCenter().x))
	{
		ball.ReboundY();
	}
	else if (ball.GetPos().x > rect.left && ball.GetPos().x < rect.right)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundX();
	}
	destroyed = true;
	
			
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
