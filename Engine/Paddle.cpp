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
		if (!coolDown && rect.IsOverlapping(ball.GetRect()))
		{
			const Vec2 ballPos = ball.GetPos();
			if (std::signbit(ball.GetVel().x) == std::signbit(ballPos.x - pos.x))
			{
				ChangeBallVel(ball, ballPos);
				ball.ReboundY();
			}
			else if (ballPos.x > rect.left && ballPos.x < rect.right)
			{
				ChangeBallVel(ball, ballPos);
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

Vec2 Paddle::GetPos() const
{
	return pos;
}

void Paddle::ChangeBallVel(Ball& ball, const Vec2& ballPos)
{
	const float dist = pos.x - ballPos.x;
	if (dist > 30.0f)
	{
		ball.ResetVelY();
		ball.ResetVelX(-1.0f);
		ball.AdjustVelY(3.0f);
	}
	else if (dist > 20.0f)
	{
		ball.ResetVelY();
		ball.ResetVelX(-1.0f);
		ball.AdjustVelY(2.0f);
	}
	else if (dist > 10.0f)
	{
		ball.ResetVelY();
		ball.ResetVelX(-1.0f);
		ball.AdjustVelX(2.0f);
	}
	else if (dist < -30.0f)
	{
		ball.ResetVelY();
		ball.ResetVelX(1.0f);
		ball.AdjustVelY(3.0f);
	}
	else if (dist < -20.0f)
	{
		ball.ResetVelY();
		ball.ResetVelX(1.0f);
		ball.AdjustVelY(2.0f);
	}
	else if (dist < -10.0f)
	{
		ball.ResetVelY();
		ball.ResetVelX(1.0f);
		ball.AdjustVelX(2.0f);
	}
	else
	{
		ball.ResetVelY();
		ball.ResetVelX(1.0f);
		ball.AdjustVelX(3.0f);
	}
}

