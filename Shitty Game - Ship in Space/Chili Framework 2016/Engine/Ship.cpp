#include "Ship.h"
#include "MainWindow.h"
#include "Graphics.h"

Bullet Ship::Shoot()
{
	return Bullet(x, y, vx, vy);
}
void Ship::Move()
{
	x = x + vx;
	y = y + vy;

	if (y + 20 >= Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - 20;
		vy = 0;
	}

	if (y - 20 <= 0)
	{
		y = 0 + 20;
		vy = 0;
	}

	if (x + 20 >= Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth - 20;
		vx = 0;
	}

	if (x - 20 <= 0)
	{
		x = 0 + 20;
		vx = 0;
	}
}

void Ship::Update(const Keyboard & kbd)
{
	if (kbd.KeyIsPressed(VK_LEFT) || kbd.KeyIsPressed(VK_RIGHT) || kbd.KeyIsPressed(VK_DOWN) || kbd.KeyIsPressed(VK_UP))
	{
		if (canMove)
		{
		}

		else
		{
			if (kbd.KeyIsPressed(VK_LEFT))
			{
				vx = vx - 1;
			}

			if (kbd.KeyIsPressed(VK_RIGHT))
			{
				vx = vx + 1;
			}

			if (kbd.KeyIsPressed(VK_DOWN))
			{
				vy = vy + 1;
			}

			if (kbd.KeyIsPressed(VK_UP))
			{
				vy = vy - 1;
			}

			canMove = true;
		}
	}

	else
	{
		canMove = false;
	}
}



