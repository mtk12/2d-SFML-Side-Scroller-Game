//Parent Class for Player, Enemy, Bullet

#pragma once
#include<SFML\Graphics.hpp>

using namespace sf;

class Entity
{

public:
	float dx, dy, x, y, speed;// moveTimer;
	int w, h, health;
	bool life, isMove, onGround;
	Texture texture;
	Sprite sprite;
	String name;
	float CurrentFrame;
	Entity(String c, float X, float Y, int W, int H, String Name);
	FloatRect getRect() 
	{
		return FloatRect(x, y, w, h);
	}
	virtual void update(float time, sf::String TileMap);//Polymorphism Virtual Function
	~Entity();
};

