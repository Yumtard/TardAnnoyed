#pragma once

#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(Vec2& pos_in, float width_in, float height_in, const Color& c);
	bool DoBallCollision(Ball& ball);
	void Draw(Graphics& gfx) const;
	RectF GetRect() const;

private:
	static constexpr float padding = 1.0f;
	float width;
	float height;
	Vec2 pos;
	Color color;
	bool destroyed = false;
};