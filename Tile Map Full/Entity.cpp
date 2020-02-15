#include "Entity.h"



Entity::Entity(String c, float X, float Y, int W, int H, String Name)
{
	x = X; y = Y; w = W; h = H; name = Name;// moveTimer = 0;
	speed = 0; health = 100; dx = 0; dy = 0;
	CurrentFrame = 0;
	life = true; onGround = false; isMove = false;
	texture.loadFromFile(c);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	sprite.setOrigin(w / 2, h / 2);
}

void Entity::update(float time, sf::String TileMap)
{
}


Entity::~Entity()
{
}
