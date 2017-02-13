#pragma once

#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(Vec2& pos_in, float width_in, float height_in, const Color& c);
	void DoBallCollision(Ball& ball);
	void Draw(Graphics& gfx) const;
	void Update(Ball& ball);
	RectF GetRect() const;

private:
	float width;
	float height;
	Vec2 pos;
	Color color;
	bool destroyed = false;
};