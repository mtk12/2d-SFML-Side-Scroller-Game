#pragma once
#include<SFML\Graphics.hpp>
#include<iostream>
#include"Entity.h"

class Player:public Entity
{
public:
	enum { left, right, up, down, jump, stay } state;
	int playerScore;

	Player(String c, float X, float Y, float W, float H, String Name);
	void update(float time, sf::String *TileMap);
	void Draw(sf::RenderWindow& window);
	void interactionWithMap(sf::String *TileMaps);
	void checkCollisionWithMap(sf::String *TileMaps, float Dx, float Dy);
	float getplayercoordinateX() { return x; }
	float getplayercoordinateY() { return y; }
	int getflag() { return flag; }
	~Player();

private:
	
	sf::Texture texture;
	std::string File;
	sf::Image image;
	int flag;
	
};

