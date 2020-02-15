#pragma once
#include<SFML\Graphics.hpp>
#include"Entity.h"

class Bullet:public Entity
{
public:
	//int direction;
	Bullet(String image, float X, float Y, int W, int H, String Name,int flag);
	void update(String *Tile, float time);
	void update(String *Tile, float time,RenderWindow &win);
	void checkCollisionWithMap(sf::String *TileMap, float Dx, float Dy);
	~Bullet();
};

