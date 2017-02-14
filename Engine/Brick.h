#pragma once

#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(RectF& Rect, const Color& c);
	bool DoBallCollision(Ball& ball);
	void Draw(Graphics& gfx) const;
	Vec2 GetCenter() const;

private:
	static constexpr float padding = 1.0f;
	Color color;
	RectF rect;
	bool destroyed = false;
};