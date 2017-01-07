#pragma once
#include "Bullet.h"
#include "Keyboard.h"

class Ship
{
public:
	void Move();
	void Update(const Keyboard& kbd );
	Bullet Shoot();
	int x = 400;
	int y = 400;
	int vx = 0;
	int vy = 0;
	bool canMove = true;

};

