#include "Ball.h"

Ball::Ball(const Vec2 & pos_in, const Vec2 & vel_in)
	:
	pos(pos_in),
	vel(vel_in)
{}

void Ball::Draw(Graphics & gfx) const
{
	const Vec2 center(pos.x + radius, pos.y + radius);
	SpriteCodex::DrawBall(center, gfx);
}

void Ball::Update(float dt)
{
	pos += vel * dt;
}

