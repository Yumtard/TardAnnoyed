#include "Paddle.h"

Paddle::Paddle(Vec2 & pos_in, Vec2 & vel_in)
	:
	pos(pos_in),
	vel(vel_in)
{}

void Paddle::Update(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos -= vel * dt;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos += vel * dt;
	}
}

void Paddle::Draw(Graphics & gfx) const
{
	gfx.DrawRect(GetRect(), color);
}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(pos, halfWidth, halfHeight);
}
