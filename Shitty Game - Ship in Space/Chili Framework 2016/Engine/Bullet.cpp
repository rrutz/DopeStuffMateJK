#include "Bullet.h"
#include "Graphics.h"


Bullet::Bullet(int x_in, int y_in, int vx_in, int vy_in)
{
	x = x_in;
	y = y_in;
	vx = vx_in;
	vy = vy_in;
}
void Bullet::Move()
{
	x += vx;
	y += vy;

	if (x <= 10 || x + 9 >= Graphics::ScreenWidth || y<= 0|| y + 9 >= Graphics::ScreenHeight)
	{
		exists = false;
	}
}

void Bullet::draw(Graphics & gfx)
{
	gfx.PaintDanger(x, y, 100, 0, 0, bulletSize);
}
