#include "Ball.h"

Ball::Ball(const Vec2 & pos_in, float speed_in)
	:
	pos(pos_in),
	resetPos(pos_in),
	speed(speed_in),
	vel(speed_in, -speed_in)
{
	vel.Normalize();
	vel *= speed;
}

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
	pos = resetPos;
	vel.x = speed;
	vel.y = -speed;
	vel.Normalize();
	vel *= speed;
}

void Ball::SetVel(Vec2 & newVel)
{
	vel = newVel;
}

float Ball::GetSpeed() const
{
	return speed;
}

