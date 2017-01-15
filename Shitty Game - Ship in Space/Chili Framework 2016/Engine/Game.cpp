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
#include "Ship.h"
#include "BadGuy.h"
#include <random>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xDist(0, 770),
	yDist(0, 570),
	xvDist(1, 2),
	yvDist(1, 2)
{
	
	for (int i = 0; i < nBadGuys; i++)
	{
		badGuys.push_back(BadGuy(xDist(rng), yDist(rng), xvDist(rng), yvDist(rng)));
	}
}

void Game::Go() // instance of frame
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame(); // this is when the new frame is shown
}


void Game::UpdateModel()
{	
	while (badGuys.size() < nBadGuys )
	{
		badGuys.push_back(BadGuy(xDist(rng), yDist(rng), xvDist(rng), yvDist(rng)));
	}
	ship.Move();
	ship.Update(wnd.kbd);

	std::vector<int> indexToDelete;
	for (int i = 0; i < nBadGuys; i++ )
	{
		badGuys[i].Update();
		if (badGuys[i].Hit(ship.x, ship.y))
		{
			indexToDelete.push_back(i);
		}
	}

	for (int i : indexToDelete)
	{
		badGuys.erase(badGuys.begin() + i);
	}


	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		bullets.push_back(Bullet(ship.x, ship.y, ship.vx, ship.vy));
	} 

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].Move();
	}

}

void Game::ComposeFrame()
{
	
	gfx.ShipImage(ship.x, ship.y, r, g, b, ship.vy, ship.vx);

	for ( BadGuy badGuy : badGuys )
	{
		badGuy.draw(gfx);
	}

	for (Bullet bullet : bullets)
	{
		if (bullet.exists)
		{
			bullet.draw(gfx);
		}
		
	}
}
