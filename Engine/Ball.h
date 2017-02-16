#pragma once

#include "RectF.h"
#include "SpriteCodex.h"
#include "Vec2.h"

class Ball
{
public:
	Ball(const Vec2& pos_in, float speed_in);
	void Draw(Graphics& gfx) const;
	void Update(float dt);
	bool DoWallCollision(const RectF& walls);
	void ReboundX();
	void ReboundY();
	RectF GetRect() const;
	Vec2 GetVel() const;
	Vec2 GetPos() const;
	void Reset();
	void SetVel(Vec2& newVel);
	float GetSpeed() const;

private:
	Vec2 pos;
	Vec2 resetPos;
	Vec2 vel;
	float speed;
	static constexpr float radius = 7.0f;
};