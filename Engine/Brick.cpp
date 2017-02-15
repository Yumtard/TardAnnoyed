#include "Brick.h"
#include <assert.h>

Brick::Brick(RectF& Rect, const Color& c, int hp_in)
	:
	rect(Rect),
	color(c),
	hp(hp_in),
	resetHp(hp_in)
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
	else if (ballPos.x > rect.left && ballPos.x < rect.right)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundX();
	}
	hp--;
	if (hp <= 0)
	{
		destroyed = true;
	}			
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

bool Brick::GetDestroyed() const
{
	return destroyed;
}

void Brick::Reset()
{
	destroyed = false;
	hp = resetHp;
}

