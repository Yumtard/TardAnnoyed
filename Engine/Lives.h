#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "SpriteCodex.h"

class Lives
{
public:
	Lives(Vec2& pos_in);
	void Decrease();
	void Draw(Graphics& gfx);
	bool LivesLeft();
	void Reset();

private:
	int nLives = 3;
	static constexpr int nLivesMax = 3;
	Vec2 position;
	Vec2 pos[nLivesMax];
};