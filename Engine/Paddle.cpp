#include "Paddle.h"

Paddle::Paddle(Vec2 & pos_in, Vec2 & vel_in)
	:
	pos(pos_in),
	vel(vel_in)
{}

void Paddle::Update(const Keyboard& kbd, float dt, RectF& walls)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos -= vel * dt;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos += vel * dt;
	}
	DoWallCollision(walls);
}

void Paddle::DoWallCollision(const RectF & walls)
{
	RectF rect = GetRect();
	if (rect.left < walls.left)
	{
		pos.x += walls.left - rect.left;
	}
	else if (rect.right >  walls.right)
	{
		pos.x -= rect.right - walls.right;
	}
}

bool Paddle::DoBallCollision(Ball & ball)
{
	if (ball.GetVel().y > 0.0f)
	{
		const RectF rect = GetRect();
		const Vec2 ballPos = ball.GetPos();
		if (!coolDown && rect.IsOverlapping(ball.GetRect()))
		{
			if (std::signbit(ball.GetVel().x) == std::signbit(ballPos.x - pos.x))
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
			coolDown = true;
			return true;
		}
	}
	return false;
}

void Paddle::Draw(Graphics & gfx) const
{
	RectF rect = GetRect();
	gfx.DrawRect(rect, wingColor);
	rect.left += wingWidth;
	rect.right -= wingWidth;
	gfx.DrawRect(rect, color);
}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(pos, halfWidth, halfHeight);
}

void Paddle::ResetCoolDown()
{
	coolDown = false;
}
