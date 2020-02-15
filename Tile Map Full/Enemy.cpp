#include "Enemy.h"
#include<iostream>

/*Enemy Constructor initializing the co-ordinates,size and type*/
Enemy::Enemy(String image, float X, float Y, int W, int H, String Name) :Entity(image, X, Y, W, H, Name) 
{
	o = 0;
	/*Enemy type that move with y axis*/
	if (name == "EasyEnemyx") {
		sprite.setTextureRect(IntRect(0, 0, w, h));
		//dy = 0.1;
		dx = 1;
	}
	/*Enemy type that move with x axis*/
	if (name == "EasyEnemy1") {
		sprite.setTextureRect(IntRect(0, 0, w, h));
		//dy = 0.1;
		dx = 0.1;
	}
	if (name == "EasyEnemy") {
		health = 200;
		sprite.setTextureRect(IntRect(0, 0, w, h));
		//dy = 0.1;
		dx = 0.1;
	}
	if (name == "Player") {
		sprite.setTextureRect(IntRect(0, 0, w, h));
		dx = 1;
	}
}

Enemy::Enemy(String image, float X, float Y, int W, int H, String Name, int flag) :Entity(image, X, Y, W, H, Name)
{
	if (name == "EasyEnemyx") {
		sprite.setTextureRect(IntRect(0, 0, w, h));
		if (flag == 0)
		{
			dx = 1;
		}
		else
		{
			dx = -1;
		}
		
	}
}

/*Checking Collision with the tiles of the map*/
void Enemy::checkCollisionWithMap(sf::String * TileMap, float Dx, float Dy)
{
	/*Collision with the map and moving*/
	if (name == "EasyEnemyx")
	{
		for (int i = y / 32; i < (y + h) / 32; i++)
			for (int j = x / 32; j<(x + w) / 32; j++)
			{
				if (TileMap[i][j] == '0' || TileMap[i][j] == 'b' || TileMap[i][j] == 'x' || TileMap[i][j] == '1' || TileMap[i][j] == 'g')
				{
					if (Dy > 0) { y = i * 32 - h; }//dy = -0.1; sprite.scale(1, -1); }
					if (Dy < 0) { y = i * 32 + 32; }//dy = 0.1; sprite.scale(1, -1); }
					if (Dx > 0) { x = j * 32 - w; dx = -0.1; sprite.scale(-1, 1); }
					if (Dx < 0) { x = j * 32 + 32;  dx = 0.1; sprite.scale(-1, 1); }
				}
			}
	}
	else if (name == "EasyEnemy1")
	{
		for (int i = y / 32; i < (y + h) / 32; i++)
			for (int j = x / 32; j<(x + w) / 32; j++)
			{
				if (TileMap[i][j] == '0' || TileMap[i][j] == 'b' || TileMap[i][j] == 'x' || TileMap[i][j] == '1' || TileMap[i][j] == 'g')
				{
					if (Dy > 0) { y = i * 32 - h; }//dy = -0.1; sprite.scale(1, -1); }
					if (Dy < 0) { y = i * 32 + 32; }//dy = 0.1; sprite.scale(1, -1); }
					if (Dx > 0) { x = j * 32 - w; dx = -0.1; sprite.scale(-1, 1); o = 1; }
					if (Dx < 0) { x = j * 32 + 32;  dx = 0.1; sprite.scale(-1, 1); o = 0; }
				}
			}
	}
	else if (name == "EasyEnemy")
	{
		for (int i = y / 32; i < (y + h) / 32; i++)
			for (int j = x / 32; j<(x + w) / 32; j++)
			{
				if (TileMap[i][j] == '0' || TileMap[i][j] == 'b' || TileMap[i][j] == 'x' || TileMap[i][j] == '1' || TileMap[i][j] == 'g')
				{
					if (Dy > 0) { y = i * 32 - h; }//dy = -0.1; sprite.scale(1, -1); }
					if (Dy < 0) { y = i * 32 + 32; }//dy = 0.1; sprite.scale(1, -1); }
					if (Dx > 0) { x = j * 32 - w; dx = -0.1; sprite.scale(-1, 1); o = 1; }
					if (Dx < 0) { x = j * 32 + 32;  dx = 0.1; sprite.scale(-1, 1); o = 0; }
				}
			}
	}
	
}

void Enemy::update(String *Tile,float time)
{
	if (name == "EasyEnemyx") 
	{
		checkCollisionWithMap(Tile, dx, 0);
		x += dx*time*15;
		sprite.setPosition(x + w / 2, y + h / 2);
		if (health <= 0) { life = false; }
	}
	if (name == "EasyEnemy1")
	{
		checkCollisionWithMap(Tile, dx,0);
		x += dx*time;
		sprite.setPosition(x + w / 2, y + h / 2);
		if (health <= 0) { life = false; }
	}
	if (name == "EasyEnemy")
	{
		checkCollisionWithMap(Tile, dx, 0);
		x += dx*time;
		sprite.setPosition(x + w / 2, y + h / 2);
		if (health <= 0) { life = false; }
	}
	if (name == "Player")
	{
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			
		}
		std::cout << "HEllo\n";
		checkCollisionWithMap(Tile, dx, 0);
		x += dx*time;
		sprite.setPosition(x + w / 2, y + h / 2);
		if (health <= 0) { life = false; }
	}
}

Enemy::~Enemy()
{
}
