#pragma once

#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(RectF& Rect, const Color& c, int hp_in);
	bool CheckBallCollision(const Ball& ball) const;
	void ExecuteBallCollision(Ball& ball);
	void Draw(Graphics& gfx) const;
	Vec2 GetCenter() const;
	bool GetDestroyed() const;
	void Reset();

private:
	static constexpr float padding = 1.0f;
	Color color;
	RectF rect;
	bool destroyed = false;
	int hp;
	int resetHp;
};