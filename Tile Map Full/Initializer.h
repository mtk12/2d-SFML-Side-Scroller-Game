#pragma once
#include<SFML\Graphics.hpp>
#include"Player.h"
#include"Enemy.h"
#include"Menu.h"
#include"Bullet.h"
#include"Camera.h"

using namespace sf;

/*Creating the Game window*/
sf::RenderWindow window(sf::VideoMode(800, 580), "Ninja VS The World");
sf::Image image;
sf::Image image1;
sf::Image imagex;
sf::Texture text2;
sf::Texture text3;
sf::Texture bgx;

sf::Sprite s;
sf::Sprite win;
sf::Sprite bg;

sf::Texture bgx2;
sf::Sprite bg2;

sf::Texture bgx3;
sf::Sprite bg3;

sf::Texture bgx4;
sf::Sprite bg4;

sf::Texture bgx5;
sf::Sprite bg5;

sf::Texture bgx6;
sf::Sprite bg6;

sf::Font font;
sf::Text text("", font, 20);
sf::Image map_image;
sf::Image mapimage;
sf::Texture map;
sf::Texture map2;
sf::Sprite s_map;
sf::Sprite smap;

Player p("ImageAssets/herox.png", 250, 450, 96, 96, "Player1");
//Player p2("ImageAssets/herox.png", 500, 150, 96, 96, "Player2");

Enemy e("ImageAssets/1.png", 850, 685, 38, 83, "EasyEnemy1");
Enemy e2("ImageAssets/Enemy.png", 1648, 429, 100, 83, "EasyEnemy1");
Enemy e3("ImageAssets/3.png", 453, 364, 39, 83, "EasyEnemy1");
Enemy e4("ImageAssets/Enemy.png", 1008, 330, 100, 83, "EasyEnemy1");
Enemy e5("ImageAssets/22.png", 1936, 585, 38, 83, "EasyEnemy1");

Enemy e6("ImageAssets/1_D.png", 850, 685, 70, 83, "EasyEnemy1");
Enemy e7("ImageAssets/2_D.png", 1616, 296, 69, 83, "EasyEnemy1");
Enemy e8("ImageAssets/3_D.png", 1362, 485, 71, 83, "EasyEnemy1");
Enemy e9("ImageAssets/E1.png", 353, 172, 72, 83, "EasyEnemy1");
Enemy e10("ImageAssets/E2.png", 2308, 685, 68, 83, "EasyEnemy1");

Enemy e11("ImageAssets/E3.png", 2308, 685, 69, 83, "EasyEnemy1");
Enemy e12("ImageAssets/E4.png", 528, 330, 92, 83, "EasyEnemy1");
Enemy e13("ImageAssets/E5.png", 1168, 520, 52, 83, "EasyEnemy1");
Enemy e14("ImageAssets/E6.png", 1696, 140, 76, 83, "EasyEnemy1");
Enemy e15("ImageAssets/E7.png", 1936, 299, 75, 83, "EasyEnemy1");

Enemy e16("ImageAssets/E8.png", 720, 135, 68, 83, "EasyEnemy1");
Enemy e17("ImageAssets/E9.png", 954, 555, 96, 83, "EasyEnemy1");
Enemy e18("ImageAssets/E10.png", 1648, 455, 82, 83, "EasyEnemy1");
Enemy e19("ImageAssets/E11.png", 1540, 233, 89, 83, "EasyEnemy1");
Enemy e20("ImageAssets/E12.png", 2384, 420, 95, 83, "EasyEnemy1");

Enemy e21("ImageAssets/E13.png", 1168, 264, 96, 83, "EasyEnemy1");
Enemy e22("ImageAssets/E14.png", 1805, 360, 99, 83, "EasyEnemy1");
Enemy e23("ImageAssets/E15.png", 1318, 488, 31, 83, "EasyEnemy1");
Enemy e24("ImageAssets/E16.png", 2042, 136, 32, 83, "EasyEnemy1");
Enemy e25("ImageAssets/E17.png", 2308, 685, 33, 83, "EasyEnemy1");

Enemy ex("ImageAssets/bx.png", 850, 529, 363, 215, "EasyEnemy");

void initializer()
{
	//menu(window);
	view.reset(sf::FloatRect(0, 0, 640, 480));
	view.zoom(1.5f);

	bgx.loadFromFile("MapAssets/b7.png");
	bg.setTexture(bgx);

	bgx2.loadFromFile("MapAssets/b2.png");
	bg2.setTexture(bgx2);

	bgx3.loadFromFile("MapAssets/b8.png");
	bg3.setTexture(bgx3);

	bgx4.loadFromFile("MapAssets/b6.png");
	bg4.setTexture(bgx4);

	bgx5.loadFromFile("MapAssets/b5.png");
	bg5.setTexture(bgx5);

	bgx6.loadFromFile("MapAssets/b.png");
	bg6.setTexture(bgx6);

	/*Lose Screen*/
	text2.loadFromFile("ImageAssets/media.png");
	s.setTexture(text2);

	text3.loadFromFile("Tiles/Win.jpg");
	win.setTexture(text3);

	/*Score and Life*/
	font.loadFromFile("Fonts/ComicSans.ttf");
	text.setStyle(Text::Bold);

	/*Map1*/
	map_image.loadFromFile("MapAssets/map.png");
	map.loadFromImage(map_image);
	s_map.setTexture(map);

	/*Map2*/
	mapimage.loadFromFile("MapAssets/map2.png");
	map2.loadFromImage(mapimage);
	smap.setTexture(map2);

}
	

	

	
	
	
