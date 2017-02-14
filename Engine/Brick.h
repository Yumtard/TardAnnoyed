#pragma once

#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(RectF& Rect, float width_in, float height_in, const Color& c);
	bool DoBallCollision(Ball& ball);
	void Draw(Graphics& gfx) const;

private:
	static constexpr float padding = 1.0f;
	float width;
	float height;
	Color color;
	RectF rect;
	bool destroyed = false;
};