#include "Paddle.h"

Paddle::Paddle(Vec2 & pos_in, Vec2 & vel_in)
	:
	pos(pos_in),
	vel(vel_in)
{}

void Paddle::Update(const Keyboard& kbd, float dt, RectF& walls, Ball& ball)
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
	DoBallCollision(ball);
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

void Paddle::DoBallCollision(Ball & ball)
{
	if (ball.GetVel().y > 0.0f)
	{
		RectF rect = GetRect();
		if (rect.IsOverlapping(ball.GetRect()))
		{
			ball.ReboundY();
		}
	}
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
