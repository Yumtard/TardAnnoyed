/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball(Vec2(300.0f, 200.0f), Vec2(400.0f, 400.0f)),
	walls(200.0f, 600.0f, 50.0f, 550.0f),
	pad(Vec2(400.0f, 500.0f), Vec2(400.0f, 0.0f)),
	padSound(L"Sounds\\arkpad.wav"),
	brickSound(L"Sounds\\arkbrick.wav")
{
	int i = 0;
	const Color colors[4] = { Colors::Red, Colors::Green, Colors::Blue, Colors::Yellow };
	const Vec2 topLeft(200.0f, 100.0f);
	for (int y = 0; y < bricksDown; ++y)
	{
		const Color c = colors[y];
		for (int x = 0; x < bricksAcross; ++x)
		{
			brick[i] = Brick(RectF(topLeft + Vec2(x * brickWidth, y * brickHeight), brickWidth, brickHeight), c);
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0.0f)
	{
		const float dt = std::min(0.0025f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	switch(gState)
	{
	case TitleState:
		while (!wnd.kbd.KeyIsEmpty())
		{
			const Keyboard::Event event = wnd.kbd.ReadKey();
			if (event.IsPress())
			{
				if (event.GetCode() == VK_RETURN)
				{
					gState = PlayState;
				}
			}
		}

		break;
	case PlayState:
		ball.Update(dt);
		int curColIndex;
		float curColDist;
		collisionHappened = false;
		for (int i = 0; i < nBricks; ++i)
		{
			float newColDist = (ball.GetPos() - brick[i].GetCenter()).GetLengthSq();

			if (brick[i].CheckBallCollision(ball))
			{
				if (collisionHappened)
				{
					if (newColDist < curColDist)
					{
						curColDist = newColDist;
						curColIndex = i;
					}
				}
				else
				{
					curColDist = newColDist;
					curColIndex = i;
					collisionHappened = true;
				}
			}
		}

		if (collisionHappened)
		{
			brick[curColIndex].ExecuteBallCollision(ball);
			brickSound.Play();
			pad.ResetCoolDown();
		}

		if (ball.DoWallCollision(walls))
		{
			if (ball.GetPos().y > pad.GetPos().y)
			{
				gState = GameOverState;
			}
			else
			{
				padSound.Play();
				pad.ResetCoolDown();
			}
		}

		if (pad.DoBallCollision(ball))
		{
			padSound.Play();
		}

		isComplete = true;
		for (int i = 0; i < nBricks; ++i)
		{
			isComplete = isComplete && brick[i].GetDestroyed();
		}
		if (isComplete)
		{
			gState = GameCompleteState;
		}

		pad.Update(wnd.kbd, dt, walls);
		break;
	case GameOverState:
		while (!wnd.kbd.KeyIsEmpty())
		{
			const Keyboard::Event event = wnd.kbd.ReadKey();
			if (event.IsPress())
			{
				if (event.GetCode() == VK_RETURN)
				{
					gState = TitleState;
				}
			}
		}
		break;
	}
}

void Game::DrawBorders()
{
	gfx.DrawRect(int(walls.left) - borderWidth, int(walls.top), int(walls.left), int(walls.bottom), Colors::White);
	gfx.DrawRect(int(walls.left), int(walls.top), int(walls.right), int(walls.top) + borderWidth, Colors::White);
	gfx.DrawRect(int(walls.right), int(walls.top), int(walls.right) + borderWidth, int(walls.bottom), Colors::White);
}

void Game::ComposeFrame()
{
	switch (gState)
	{
	case TitleState:
		SpriteCodex::DrawTitle(Vec2(300.0f, 150.0f), gfx);
		break;
		
	case PlayState:
		DrawBorders();
		ball.Draw(gfx);
		for (const Brick& b : brick)
		{
			b.Draw(gfx);
		}
		pad.Draw(gfx);
		break;

	case GameOverState:
		SpriteCodex::DrawGameOver(Vec2(275.0f, 250.0f), gfx);
		break;

	case GameCompleteState:
		SpriteCodex::DrawComplete(Vec2(275.0f, 250.0f), gfx);
		break;
	}	
}
