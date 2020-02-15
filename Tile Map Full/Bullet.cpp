#include "Bullet.h"
#include<iostream>

Bullet::Bullet(String image, float X, float Y, int W, int H, String Name,int flag) :Entity(image, X, Y, W, H, Name)
{
	if (name == "Player") {
		if (flag == 0)
		{
			sprite.setTextureRect(IntRect(0, 0, w, h));
			dx = 5;
		}
		else
		{
			sprite.setTextureRect(IntRect(0, 0, w, h));
			dx = -5;
		}
		
	}
}

void Bullet::update(String *Tile, float time)
{
	if (name == "Player")
	{	
		
		std::cout << "HEllo\n";
		checkCollisionWithMap(Tile, dx, 0);
		x += dx*time;
		sprite.setPosition(x + w / 2, y + h / 2);
		if (health <= 0) { life = false; }
	}
}

void Bullet::update(String * Tile, float time, RenderWindow & win)
{
	for (int c = 0; c<2; c++)
	{
		std::cout << "HEllo\n";
		checkCollisionWithMap(Tile, dx, 0);
		x += dx*time;
		sprite.setPosition(x + w / 2 , y + h / 2);
		if (health <= 0) { life = false; }
		win.draw(sprite);
	}
}


void Bullet::checkCollisionWithMap(sf::String *TileMap, float Dx, float Dy)
{
	if (name == "Player")
	{
		for (int i = y / 32; i < (y + h) / 32; i++)
			for (int j = x / 32; j<(x + w) / 32; j++)
			{
				if (TileMap[i][j] == '0' || TileMap[i][j] == 'b' || TileMap[i][j] == 'x' || TileMap[i][j] == '1' || TileMap[i][j] == 'g')
				{
					if (Dy > 0) { y = i * 32 - h; }//dy = -0.1; sprite.scale(1, -1); }
					if (Dy < 0) { y = i * 32 + 32; }//dy = 0.1; sprite.scale(1, -1); }
					if (Dx > 0) { x = j * 32 - w; dx = -0.1; sprite.scale(-1, 1);  }
					if (Dx < 0) { x = j * 32 + 32;  dx = 0.1; sprite.scale(-1, 1); }
				}
			}
	}
}

Bullet::~Bullet()
{
}
