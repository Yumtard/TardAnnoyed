#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float left_in, float right_in, float top_in, float bottom_in);
	RectF(const Vec2& topleft, const Vec2& bottomright);
	RectF(const Vec2&  topleft, float width, float height);
	bool IsOverlapping(RectF& other);
	static RectF FromCenter(const Vec2& center, float halfWidth, float halfHeight);

public:
	float left;
	float right;
	float top;
	float bottom;
};