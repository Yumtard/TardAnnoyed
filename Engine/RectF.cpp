#include "RectF.h"

RectF::RectF(float left_in, float right_in, float top_in, float bottom_in)
	:
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)
{}

RectF::RectF(const Vec2 & topleft, const Vec2 & bottomright)
	:
	RectF(topleft.x, bottomright.x, topleft.y, bottomright.y)
{}

RectF::RectF(const Vec2 & topleft, float width, float height)
	:
	RectF(topleft, topleft + Vec2(width, height))
{}

bool RectF::IsOverlapping(RectF & other)
{
	return left < other.right && right > other.left &&
		top < other.bottom && bottom > other.top;
}

RectF RectF::FromCenter(const Vec2 & center, float halfWidth, float halfHeight)
{
	Vec2 half(halfWidth, halfHeight);
	return RectF(center - half, center + half);
}

RectF RectF::GetExpanded(float offset) const
{
	return RectF(left - offset, right + offset, top - offset, bottom + offset);
}
