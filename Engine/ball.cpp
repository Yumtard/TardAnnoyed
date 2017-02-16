#include "Ball.h"

Ball::Ball(const Vec2 & pos_in, const Vec2 & vel_in)
	:
	pos(pos_in),
	vel(vel_in),
	velReset(vel_in)
{}

void Ball::Draw(Graphics & gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt)
{
	pos += vel * dt;
}

bool Ball::DoWallCollision(const RectF & walls)
{
	const RectF rect = GetRect();
	bool collided = false;
	
	if (rect.left < walls.left)
	{
		collided = true;
		pos.x += walls.left - rect.left;
		ReboundX();
	}
	else if (rect.right > walls.right)
	{
		collided = true;
		pos.x -= rect.right - walls.right;
		ReboundX();
	}
	if (rect.top < walls.top)
	{
		collided = true;
		pos.y += walls.top - rect.top;
		ReboundY();
	}
	else if (rect.bottom > walls.bottom)
	{
		collided = true;
		pos.y -= rect.bottom - walls.bottom;
		ReboundY();
	}

	return collided;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(pos, radius, radius);
}

Vec2 Ball::GetVel() const
{
	return vel;
}

Vec2 Ball::GetPos() const
{
	return pos;
}

void Ball::Reset()
{
	pos.x = 300.0f; 
	pos.y = 500.0f;
	vel.x = 400.0f;
	vel.y = -400.0f;
}

void Ball::ResetVelY()
{
	vel.y = -velReset.y;
}
void Ball::ResetVelX(float x)
{
	vel.x = (velReset.x * x);
}

void Ball::AdjustVelX(float x)
{
	vel.x /= x;
}

void Ball::AdjustVelY(float x)
{
	vel.y /= x;
}

