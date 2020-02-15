#include "Player.h"

using namespace sf;

/*Player constructor initializing the co-ordiates and size*/
Player::Player(String c, float X, float Y, float W, float H, String Name) :Entity(c, X, Y, W, H, Name)
{
	flag = 0;
	playerScore = 0; state = stay;
	if (name == "Player1") {
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}
}

/*Update the player with the keyboard buffer*/
void Player::update(float time, sf::String *TileMap)
{
	sprite.setTextureRect(IntRect(0, 0, w, h));
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		state = left;
		speed = 0.15;
		CurrentFrame += 0.005*time;
		if (CurrentFrame > 2) CurrentFrame -= 2;
		sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96));
		flag = 1;
	}

	 if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		 state = right;
		 speed = 0.15;
		CurrentFrame += 0.005*time;
		if (CurrentFrame > 2) CurrentFrame -= 2;
		sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 198, 96, 96));
		flag = 0;
	}

	 if (Keyboard::isKeyPressed(Keyboard::Up)&&(onGround))
	{
		 state = jump; dy = -0.7; onGround = false;
		CurrentFrame += 0.005*time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 288, 96, 96));
	}
	 if (onGround == false)
	 {
		 sprite.setTextureRect(IntRect(0, 305, 95, 79));
	 }
	 /*Player States*/
	 switch (state)
	 {
	 case right: dx = speed; break;
	 case left: dx = -speed; break;
	 case up: break;
	 case down: break;
	 case jump: break;
	 case stay: break;		
	 }
	 x += dx*time;
	 checkCollisionWithMap(TileMap ,dx, 0);
	 y += dy*time;
	 checkCollisionWithMap(TileMap ,0, dy);
	 if (!isMove) speed = 0;
	 if (playerScore == 100 || playerScore == 201 || playerScore == 302 || playerScore == 403 || playerScore == 505)
	 {
		 x = 250;
		 y = 450;
		 playerScore++;
	 }
	 
	 sprite.setPosition(x + w / 2, y + h / 2);
	
	 if (health <= 0) { life = false; }
	 dy = dy + 0.0015*time;

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

/*void Player::interactionWithMap(sf::String *TileMaps)
{
	for (int i = y / 32; i < (y + h) / 32; i++)
		for (int j = x / 32; j<(x + w) / 32; j++)
		{
			if (TileMaps[i][j] == '0')
			{
				if (dy>0)
				{
					y = i * 32 - h;
				}
				if (dy<0)
				{
					y = i * 32 + 32;
				}
				if (dx>0)
				{
					x = j * 32 - w;
				}
				if (dx < 0)
				{
					x = j * 32 + 32;
				}
			}


			if (TileMaps[i][j] == 's') {
				playerScore++;
				TileMaps[i][j] = ' ';
			}

			if (TileMaps[i][j] == 'f') {
				health -= 40;
				TileMaps[i][j] = ' ';
			}

			if (TileMaps[i][j] == 'h') {
				health += 20;
				TileMaps[i][j] = ' ';
			}
		}
}*/

void Player::checkCollisionWithMap(sf::String *TileMap,float Dx, float Dy)
{
	for (int i = y / 32; i < (y + h) / 32; i++)
		for (int j = x / 32; j<(x + w) / 32; j++)
		{
			if (TileMap[i][j] == '0' || TileMap[i][j] == 'b' || TileMap[i][j] == 'x' || TileMap[i][j] == '1' || TileMap[i][j] == 'g')
			{
				if (Dy>0) { y = i * 32 - h;  dy = 0; onGround = true; }
				if (Dy<0) { y = i * 32 + 32;  dy = 0; }
				if (Dx>0) { x = j * 32 - w; }
				if (Dx<0) { x = j * 32 + 32; }
			}
			if (TileMap[i][j] == 's') {
				playerScore+=5;
				TileMap[i][j] = ' ';
			}

			if (TileMap[i][j] == 'f') {
				//health -= 40;
				//health = 0;
				//TileMap[i][j] = ' ';
			}

			if (TileMap[i][j] == 'h') {
				health += 10;
				TileMap[i][j] = ' ';
			}
		}
}
Player::~Player()
{
}
