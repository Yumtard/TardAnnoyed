#pragma once

#include "MainWindow.h"
#include "Ball.h"
#include "Vec2.h"

class Paddle
{
public:
	Paddle(Vec2& pos_in, Vec2& vel_in);
	void Update(const Keyboard& kbd, float dt, RectF& walls);
	void DoWallCollision(const RectF& walls);
	bool DoBallCollision(Ball& ball);
	void Draw(Graphics& gfx) const;
	RectF GetRect() const;
	void ResetCoolDown();

private:
	static constexpr float halfWidth = 50.0f;
	static constexpr float halfHeight = 10.0f;
	static constexpr float wingWidth = 20.0f;

	Vec2 pos;
	Vec2 vel;
	Color color = Colors::White;
	Color wingColor = Colors::Red;
	bool coolDown = false;
};