#pragma once

#include "MainWindow.h"
#include "Ball.h"
#include "Vec2.h"

class Paddle
{
public:
	Paddle(Vec2& pos_in, Vec2& vel_in);
	void Update(const Keyboard& kbd, float dt, RectF& walls, Ball& ball);
	void DoWallCollision(const RectF& walls);
	void DoBallCollision(Ball& ball);
	void Draw(Graphics& gfx) const;
	RectF GetRect() const;

private:
	static constexpr float halfWidth = 50.0f;
	static constexpr float halfHeight = 10.0f;
	Vec2 pos;
	Vec2 vel;
	Color color = Colors::White;
};