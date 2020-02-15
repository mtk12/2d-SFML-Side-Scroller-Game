#pragma once
#include<SFML\Graphics.hpp>
#include"Entity.h"

class Enemy:public Entity//Inheritance
{
public:
	int o;
	Enemy(String image, float X, float Y, int W, int H, String Name);//Overloading
	Enemy(String image, float X, float Y, int W, int H, String Name,int flag);//overloading
	void checkCollisionWithMap(sf::String *TileMaps, float Dx, float Dy);
	void update(String *Tile,float time);
	int getflag() { return o; }
	~Enemy();
};

