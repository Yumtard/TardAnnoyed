/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Ball.h"
#include "RectF.h"
#include "FrameTimer.h"
#include "Brick.h"
#include "Paddle.h"
#include "Sound.h"
#include "Lives.h"

class Game
{
public:
	enum GameState
	{
		TitleState, PlayState, GameOverState, GameCompleteState
	};
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel(float dt);
	/********************************/
	/*  User Functions              */
	void DrawBorders();
	bool Counter();
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	Ball ball;
	FrameTimer ft;
	RectF walls;
	Paddle pad;
	
	static constexpr float brickWidth = 40.0f;
	static constexpr float brickHeight = 20.0f;
	static constexpr int bricksAcross = 10;
	static constexpr int bricksDown = 5;
	static constexpr int nBricks = bricksAcross * bricksDown;

	Brick brick[nBricks];
	GameState gState = TitleState;
	Sound padSound;
	Sound brickSound;
	static constexpr int borderWidth = 10;
	bool collisionHappened;
	bool isComplete;
	Lives lives;
	int counter = 0;
	int startGame = 240;
	/********************************/
};