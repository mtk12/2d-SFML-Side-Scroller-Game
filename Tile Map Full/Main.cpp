#include<SFML/Graphics.hpp>
#include"Map.h"
#include"Map2.h"
#include"Map3.h"
#include"Map4.h"
#include"Map5.h"
#include"Boss.h"
#include"Bullet.h"
#include"Pause.h"
#include"Initializer.h"
#include<iostream>
#include<sstream>

using namespace sf;

int main()
{
	initializer();
	menu(window);
	/*FrameRate*/
	sf::Clock clock;
	Clock gameTimeClock;
	int gameTime = 0;
	bool de=false;
	
	/*GAME LOOP*/
	while (window.isOpen())
	{
		
		float time = clock.getElapsedTime().asMicroseconds();//framerates

		/*Setting the view and gametime*/
		if (p.life) gameTime = gameTimeClock.getElapsedTime().asSeconds();
		else { view.move(0.8, 0); }

		clock.restart();
		time = time / 800;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		/*If life is true it will run*/
		if (p.life==true)
		{
			getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
		}
		
		/*Resizing the view*/
		changeview();
		window.setView(view);
		window.clear();

		/*HUD display*/
		std::ostringstream playerHealthString, gameTimeString, playerscore, fra;
		playerHealthString << p.health; gameTimeString << gameTime;	playerscore << p.playerScore; fra << time;
		text.setString("Score: " + playerscore.str() + "\nHealth:" + playerHealthString.str() + "\nGame Time: " + gameTimeString.str() + "\nFrames: " + fra.str());

		/*Conditions to check if score is greater than 100 than next map will be loaded*/
		if (de == false)
		{
			if (p.playerScore < 100)
			{
				p.sprite.setColor(Color::White);
				window.draw(bg);
				p.update(time, TileMap);
				std::cout << p.playerScore << "\t";
				e.update(TileMap, time);
				e2.update(TileMap, time);
				e3.update(TileMap, time);
				e4.update(TileMap, time);
				e5.update(TileMap, time);
				Bullet ez("ImageAssets/Kunai.png", p.sprite.getPosition().x, p.sprite.getPosition().y, 50, 10, "Player", p.getflag());
				Bullet es("ImageAssets/Kunai1.png", p.sprite.getPosition().x, p.sprite.getPosition().y, 50, 10, "Player", p.getflag());

				if (Keyboard::isKeyPressed(Keyboard::S))
				{
					if (p.getflag() == 0)
					{
						ez.update(TileMap, time, window);
					}
					else
					{
						es.update(TileMap, time, window);
					}

				}

				for (int i = 0; i < HEIGHT_MAP; i++)
					for (int j = 0; j < WIDTH_MAP; j++)
					{
						if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 0, 0));
						if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));
						if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));
						if ((TileMap[i][j] == 'f')) s_map.setTextureRect(IntRect(96, 0, 32, 32));
						if ((TileMap[i][j] == 'h')) s_map.setTextureRect(IntRect(128, 0, 32, 32));
						if ((TileMap[i][j] == 'b')) s_map.setTextureRect(IntRect(160, 0, 32, 32));
						if ((TileMap[i][j] == 'x')) s_map.setTextureRect(IntRect(192, 0, 32, 32));
						if ((TileMap[i][j] == '1')) s_map.setTextureRect(IntRect(224, 0, 32, 32));
						if ((TileMap[i][j] == 'g')) s_map.setTextureRect(IntRect(254, 0, 32, 32));
						s_map.setPosition(j * 32, i * 32);

						window.draw(s_map);
					}
				if (ez.getRect().intersects(e.getRect()) || es.getRect().intersects(e.getRect()))
				{
					if (e.health != 0)
					{
						e.health -= 1;

					}
				}
				if (ez.getRect().intersects(e2.getRect()) || es.getRect().intersects(e2.getRect()))
				{
					if (e2.health != 0)
					{
						e2.health -= 1;

					}
				}
				if (ez.getRect().intersects(e3.getRect()) || es.getRect().intersects(e3.getRect()))
				{
					if (e3.health != 0)
					{
						e3.health -= 1;

					}
				}
				if (ez.getRect().intersects(e4.getRect()) || es.getRect().intersects(e4.getRect()))
				{
					if (e4.health != 0)
					{
						e4.health -= 1;

					}
				}
				if (ez.getRect().intersects(e5.getRect()) || es.getRect().intersects(e5.getRect()))
				{
					if (e5.health != 0)
					{
						e5.health -= 1;

					}
				}
				if (p.getRect().intersects(e.getRect()))
				{
					if (e.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e.dx = 0; p.dy = -0.2; e.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e2.getRect()))
				{
					if (e2.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e2.dx = 0; p.dy = -0.2; e2.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e3.getRect()))
				{
					if (e3.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e3.dx = 0; p.dy = -0.2; e3.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e4.getRect()))
				{
					if (e4.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e4.dx = 0; p.dy = -0.2; e4.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e5.getRect()))
				{
					if (e5.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e5.dx = 0; p.dy = -0.2; e5.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (e.life == true)
				{
					window.draw(e.sprite);
				}
				if (e2.life == true)
				{
					window.draw(e2.sprite);
				}
				if (e3.life == true)
				{
					window.draw(e3.sprite);
				}
				if (e4.life == true)
				{
					window.draw(e4.sprite);
				}
				if (e5.life == true)
				{
					window.draw(e5.sprite);
				}
			}
			else if (p.playerScore > 100 && p.playerScore < 200)
			{
				p.sprite.setColor(Color::White);
				window.draw(bg2);
				p.update(time, TileMaps);
				std::cout << p.playerScore << "b\t";
				e6.update(TileMaps, time);
				e7.update(TileMaps, time);
				e8.update(TileMaps, time);
				e9.update(TileMaps, time);
				e10.update(TileMaps, time);
				Bullet ez("ImageAssets/Kunai.png", p.sprite.getPosition().x, p.sprite.getPosition().y, 50, 10, "Player", p.getflag());
				Bullet es("ImageAssets/Kunai1.png", p.sprite.getPosition().x, p.sprite.getPosition().y, 50, 10, "Player", p.getflag());

				if (Keyboard::isKeyPressed(Keyboard::S))
				{
					if (p.getflag() == 0)
					{
						ez.update(TileMap, time, window);
					}
					else
					{
						es.update(TileMap, time, window);
					}

				}

				for (int i = 0; i < HEIGHT; i++)
					for (int j = 0; j < WIDTH; j++)
					{
						if (TileMaps[i][j] == ' ')  smap.setTextureRect(IntRect(0, 0, 0, 0));
						if (TileMaps[i][j] == 's')  smap.setTextureRect(IntRect(32, 0, 32, 32));
						if ((TileMaps[i][j] == '0')) smap.setTextureRect(IntRect(64, 0, 32, 32));
						if ((TileMaps[i][j] == 'f')) smap.setTextureRect(IntRect(96, 0, 32, 32));
						if ((TileMaps[i][j] == 'h')) smap.setTextureRect(IntRect(128, 0, 32, 32));
						if ((TileMaps[i][j] == 'b')) smap.setTextureRect(IntRect(160, 0, 32, 32));
						if ((TileMaps[i][j] == 'x')) smap.setTextureRect(IntRect(192, 0, 32, 32));
						if ((TileMaps[i][j] == '1')) smap.setTextureRect(IntRect(224, 0, 32, 32));
						if ((TileMaps[i][j] == 'g')) smap.setTextureRect(IntRect(254, 0, 32, 32));
						smap.setPosition(j * 32, i * 32);

						window.draw(smap);
					}
				if (ez.getRect().intersects(e6.getRect()) || es.getRect().intersects(e6.getRect()))
				{
					if (e6.health != 0)
					{
						e6.health -= 1;

					}
				}
				if (ez.getRect().intersects(e7.getRect()) || es.getRect().intersects(e7.getRect()))
				{
					if (e7.health != 0)
					{
						e7.health -= 1;

					}
				}
				if (ez.getRect().intersects(e8.getRect()) || es.getRect().intersects(e8.getRect()))
				{
					if (e8.health != 0)
					{
						e8.health -= 1;

					}
				}
				if (ez.getRect().intersects(e9.getRect()) || es.getRect().intersects(e9.getRect()))
				{
					if (e9.health != 0)
					{
						e9.health -= 1;

					}
				}
				if (ez.getRect().intersects(e10.getRect()) || es.getRect().intersects(e10.getRect()))
				{
					if (e10.health != 0)
					{
						e10.health -= 1;

					}
				}
				if (p.getRect().intersects(e6.getRect()))
				{
					if (e6.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e6.dx = 0; p.dy = -0.2; e6.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e7.getRect()))
				{
					if (e7.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e7.dx = 0; p.dy = -0.2; e7.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e8.getRect()))
				{
					if (e8.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e8.dx = 0; p.dy = -0.2; e8.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e9.getRect()))
				{
					if (e9.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e9.dx = 0; p.dy = -0.2; e9.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e10.getRect()))
				{
					if (e10.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e10.dx = 0; p.dy = -0.2; e10.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (e6.life == true)
				{
					window.draw(e6.sprite);
				}
				if (e7.life == true)
				{
					window.draw(e7.sprite);
				}
				if (e8.life == true)
				{
					window.draw(e8.sprite);
				}
				if (e9.life == true)
				{
					window.draw(e9.sprite);
				}
				if (e10.life == true)
				{
					window.draw(e10.sprite);
				}
			}
			else if (p.playerScore > 200 && p.playerScore < 300)
			{
				p.sprite.setColor(Color::White);
				window.draw(bg3);
				p.update(time, TileMap3);
				std::cout << p.playerScore << "b\t";
				e11.update(TileMap3, time);
				e12.update(TileMap3, time);
				e13.update(TileMap3, time);
				e14.update(TileMap3, time);
				e15.update(TileMap3, time);
				Bullet ez("ImageAssets/Kunai.png", p.sprite.getPosition().x, p.sprite.getPosition().y, 50, 10, "Player", p.getflag());
				Bullet es("ImageAssets/Kunai1.png", p.sprite.getPosition().x, p.sprite.getPosition().y, 50, 10, "Player", p.getflag());
				if (Keyboard::isKeyPressed(Keyboard::S))
				{
					if (p.getflag() == 0)
					{
						ez.update(TileMap, time, window);
					}
					else
					{
						es.update(TileMap, time, window);
					}
				}
				for (int i = 0; i < HEIGHTx; i++)
					for (int j = 0; j < WIDTHy; j++)
					{
						if (TileMap3[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 0, 0));
						if (TileMap3[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));
						if ((TileMap3[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));
						if ((TileMap3[i][j] == 'f')) s_map.setTextureRect(IntRect(96, 0, 32, 32));
						if ((TileMap3[i][j] == 'h')) s_map.setTextureRect(IntRect(128, 0, 32, 32));
						if ((TileMap3[i][j] == 'b')) s_map.setTextureRect(IntRect(160, 0, 32, 32));
						if ((TileMap3[i][j] == 'x')) s_map.setTextureRect(IntRect(192, 0, 32, 32));
						if ((TileMap3[i][j] == '1')) s_map.setTextureRect(IntRect(224, 0, 32, 32));
						if ((TileMap3[i][j] == 'g')) s_map.setTextureRect(IntRect(254, 0, 32, 32));
						s_map.setPosition(j * 32, i * 32);

						window.draw(s_map);
					}
				if (ez.getRect().intersects(e11.getRect()) || es.getRect().intersects(e11.getRect()))
				{
					if (e11.health != 0)
					{
						e11.health -= 1;

					}
				}
				if (ez.getRect().intersects(e12.getRect()) || es.getRect().intersects(e12.getRect()))
				{
					if (e12.health != 0)
					{
						e12.health -= 1;

					}
				}
				if (ez.getRect().intersects(e13.getRect()) || es.getRect().intersects(e13.getRect()))
				{
					if (e13.health != 0)
					{
						e13.health -= 1;

					}
				}
				if (ez.getRect().intersects(e14.getRect()) || es.getRect().intersects(e14.getRect()))
				{
					if (e14.health != 0)
					{
						e14.health -= 1;

					}
				}
				if (ez.getRect().intersects(e15.getRect()) || es.getRect().intersects(e15.getRect()))
				{
					if (e15.health != 0)
					{
						e15.health -= 1;

					}
				}
				if (p.getRect().intersects(e11.getRect()))
				{
					if (e11.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e11.dx = 0; p.dy = -0.2; e11.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e12.getRect()))
				{
					if (e12.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e12.dx = 0; p.dy = -0.2; e12.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e13.getRect()))
				{
					if (e13.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e13.dx = 0; p.dy = -0.2; e13.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e14.getRect()))
				{
					if (e14.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e14.dx = 0; p.dy = -0.2; e14.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e15.getRect()))
				{
					if (e15.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e15.dx = 0; p.dy = -0.2; e15.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (e11.life == true)
				{
					window.draw(e11.sprite);
				}
				if (e12.life == true)
				{
					window.draw(e12.sprite);
				}
				if (e13.life == true)
				{
					window.draw(e13.sprite);
				}
				if (e14.life == true)
				{
					window.draw(e14.sprite);
				}
				if (e15.life == true)
				{
					window.draw(e15.sprite);
				}
			}
			else if (p.playerScore > 300 && p.playerScore < 400)
			{
				p.sprite.setColor(Color::White);
				window.draw(bg4);
				p.update(time, TileMap4);
				std::cout << p.playerScore << "b\t";
				e16.update(TileMap4, time);
				e17.update(TileMap4, time);
				e18.update(TileMap4, time);
				e19.update(TileMap4, time);
				e20.update(TileMap4, time);
				Bullet ez("ImageAssets/Kunai.png", p.sprite.getPosition().x, p.sprite.getPosition().y, 50, 10, "Player", p.getflag());
				Bullet es("ImageAssets/Kunai1.png", p.sprite.getPosition().x, p.sprite.getPosition().y, 50, 10, "Player", p.getflag());

				if (Keyboard::isKeyPressed(Keyboard::S))
				{
					if (p.getflag() == 0)
					{
						ez.update(TileMap, time, window);
					}
					else
					{
						es.update(TileMap, time, window);
					}

				}
				for (int i = 0; i < HEIGHTx; i++)
					for (int j = 0; j < WIDTHy; j++)
					{
						if (TileMap4[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 0, 0));
						if (TileMap4[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));
						if ((TileMap4[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));
						if ((TileMap4[i][j] == 'f')) s_map.setTextureRect(IntRect(96, 0, 32, 32));
						if ((TileMap4[i][j] == 'h')) s_map.setTextureRect(IntRect(128, 0, 32, 32));
						if ((TileMap4[i][j] == 'b')) s_map.setTextureRect(IntRect(160, 0, 32, 32));
						if ((TileMap4[i][j] == 'x')) s_map.setTextureRect(IntRect(192, 0, 32, 32));
						if ((TileMap4[i][j] == '1')) s_map.setTextureRect(IntRect(224, 0, 32, 32));
						if ((TileMap4[i][j] == 'g')) s_map.setTextureRect(IntRect(254, 0, 32, 32));
						s_map.setPosition(j * 32, i * 32);

						window.draw(s_map);
					}
				if (ez.getRect().intersects(e16.getRect()) || es.getRect().intersects(e16.getRect()))
				{
					if (e16.health != 0)
					{
						e16.health -= 1;

					}
				}
				if (ez.getRect().intersects(e17.getRect()) || es.getRect().intersects(e17.getRect()))
				{
					if (e17.health != 0)
					{
						e17.health -= 1;

					}
				}
				if (ez.getRect().intersects(e18.getRect()) || es.getRect().intersects(e18.getRect()))
				{
					if (e18.health != 0)
					{
						e18.health -= 1;

					}
				}
				if (ez.getRect().intersects(e19.getRect()) || es.getRect().intersects(e19.getRect()))
				{
					if (e19.health != 0)
					{
						e19.health -= 1;

					}
				}
				if (ez.getRect().intersects(e20.getRect()) || es.getRect().intersects(e20.getRect()))
				{
					if (e20.health != 0)
					{
						e20.health -= 1;

					}
				}
				if (p.getRect().intersects(e16.getRect()))
				{
					if (e16.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e16.dx = 0; p.dy = -0.2; e16.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e17.getRect()))
				{
					if (e17.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e17.dx = 0; p.dy = -0.2; e17.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e18.getRect()))
				{
					if (e18.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e18.dx = 0; p.dy = -0.2; e18.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e19.getRect()))
				{
					if (e19.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e19.dx = 0; p.dy = -0.2; e19.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e20.getRect()))
				{
					if (e20.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e20.dx = 0; p.dy = -0.2; e20.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (e16.life == true)
				{
					window.draw(e16.sprite);
				}
				if (e17.life == true)
				{
					window.draw(e17.sprite);
				}
				if (e18.life == true)
				{
					window.draw(e18.sprite);
				}
				if (e19.life == true)
				{
					window.draw(e19.sprite);
				}
				if (e20.life == true)
				{
					window.draw(e20.sprite);
				}
			}
			else if (p.playerScore > 400 && p.playerScore < 500)
			{
				p.sprite.setColor(Color::White);
				window.draw(bg5);
				p.update(time, TileMap5);
				std::cout << p.playerScore << "b\t";
				e21.update(TileMap5, time);
				e22.update(TileMap5, time);
				e23.update(TileMap5, time);
				e24.update(TileMap5, time);
				e25.update(TileMap5, time);
				Bullet ez("ImageAssets/Kunai.png", p.sprite.getPosition().x, p.sprite.getPosition().y, 50, 10, "Player", p.getflag());
				Bullet es("ImageAssets/Kunai1.png", p.sprite.getPosition().x, p.sprite.getPosition().y, 50, 10, "Player", p.getflag());
				if (Keyboard::isKeyPressed(Keyboard::S))
				{
					if (p.getflag() == 0)
					{
						ez.update(TileMap, time, window);
					}
					else
					{
						es.update(TileMap, time, window);
					}

				}
				for (int i = 0; i < HEIGHTh; i++)
					for (int j = 0; j < WIDTHw; j++)
					{
						if (TileMap5[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 0, 0));
						if (TileMap5[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));
						if ((TileMap5[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));
						if ((TileMap5[i][j] == 'f')) s_map.setTextureRect(IntRect(96, 0, 32, 32));
						if ((TileMap5[i][j] == 'h')) s_map.setTextureRect(IntRect(128, 0, 32, 32));
						if ((TileMap5[i][j] == 'b')) s_map.setTextureRect(IntRect(160, 0, 32, 32));
						if ((TileMap5[i][j] == 'x')) s_map.setTextureRect(IntRect(192, 0, 32, 32));
						if ((TileMap5[i][j] == '1')) s_map.setTextureRect(IntRect(224, 0, 32, 32));
						if ((TileMap5[i][j] == 'g')) s_map.setTextureRect(IntRect(254, 0, 32, 32));
						s_map.setPosition(j * 32, i * 32);

						window.draw(s_map);
					}
				if (ez.getRect().intersects(e21.getRect()) || es.getRect().intersects(e21.getRect()))
				{
					if (e21.health != 0)
					{
						e21.health -= 1;

					}
				}
				if (ez.getRect().intersects(e22.getRect()) || es.getRect().intersects(e22.getRect()))
				{
					if (e22.health != 0)
					{
						e22.health -= 1;

					}
				}
				if (ez.getRect().intersects(e23.getRect()) || es.getRect().intersects(e23.getRect()))
				{
					if (e23.health != 0)
					{
						e23.health -= 1;

					}
				}
				if (ez.getRect().intersects(e24.getRect()) || es.getRect().intersects(e24.getRect()))
				{
					if (e24.health != 0)
					{
						e24.health -= 1;

					}
				}
				if (ez.getRect().intersects(e25.getRect()) || es.getRect().intersects(e25.getRect()))
				{
					if (e25.health != 0)
					{
						e25.health -= 1;

					}
				}
				if (p.getRect().intersects(e21.getRect()))
				{
					if (e21.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e21.dx = 0; p.dy = -0.2; e21.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e22.getRect()))
				{
					if (e22.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e22.dx = 0; p.dy = -0.2; e22.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e23.getRect()))
				{
					if (e23.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e23.dx = 0; p.dy = -0.2; e23.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e24.getRect()))
				{
					if (e24.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e24.dx = 0; p.dy = -0.2; e24.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(e25.getRect()))
				{
					if (e25.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { e25.dx = 0; p.dy = -0.2; e25.health = 0; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (e21.life == true)
				{
					window.draw(e21.sprite);
				}
				if (e22.life == true)
				{
					window.draw(e22.sprite);
				}
				if (e23.life == true)
				{
					window.draw(e23.sprite);
				}
				if (e24.life == true)
				{
					window.draw(e24.sprite);
				}
				if (e25.life == true)
				{
					window.draw(e25.sprite);
				}
			}
			else if (p.playerScore > 500)
			{
				p.sprite.setColor(Color::White);
				window.draw(bg6);
				p.update(time, TileMapb);
				ex.update(TileMapb, time);

				Enemy en("MapAssets/firex.png", ex.sprite.getPosition().x, ex.sprite.getPosition().y, 100, 100, "EasyEnemyx", ex.getflag());
				Enemy ei("MapAssets/fire.png", ex.sprite.getPosition().x, ex.sprite.getPosition().y - 10, 70, 100, "EasyEnemyx", ex.getflag());
				Bullet ez("ImageAssets/Kunai.png", p.sprite.getPosition().x, p.sprite.getPosition().y, 50, 10, "Player", p.getflag());
				Bullet es("ImageAssets/Kunai1.png", p.sprite.getPosition().x, p.sprite.getPosition().y, 50, 10, "Player", p.getflag());

				if (Keyboard::isKeyPressed(Keyboard::S))
				{
					if (p.getflag() == 0)
					{
						ez.update(TileMap, time, window);
					}
					else
					{
						es.update(TileMap, time, window);
					}

				}
				if (ex.life)
				{
					en.update(TileMapb, time);
					ei.update(TileMapb, time);
					window.draw(ei.sprite);
					window.draw(en.sprite);
				}
				for (int i = 0; i < HEIGHTh; i++)
					for (int j = 0; j < WIDTHw; j++)
					{
						if (TileMapb[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 0, 0));
						if (TileMapb[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));
						if ((TileMapb[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));
						if ((TileMapb[i][j] == 'f')) s_map.setTextureRect(IntRect(96, 0, 32, 32));
						if ((TileMapb[i][j] == 'h')) s_map.setTextureRect(IntRect(128, 0, 32, 32));
						if ((TileMapb[i][j] == 'b')) s_map.setTextureRect(IntRect(160, 0, 32, 32));
						if ((TileMapb[i][j] == 'x')) s_map.setTextureRect(IntRect(192, 0, 32, 32));
						if ((TileMapb[i][j] == '1')) s_map.setTextureRect(IntRect(224, 0, 32, 32));
						if ((TileMapb[i][j] == 'g')) s_map.setTextureRect(IntRect(254, 0, 32, 32));
						if ((TileMapb[i][j] == 'n')) s_map.setTextureRect(IntRect(286, 0, 32, 32));
						s_map.setPosition(j * 32, i * 32);

						window.draw(s_map);
					}
				if (ez.getRect().intersects(ex.getRect()) || es.getRect().intersects(ex.getRect()))
				{
					if (ex.health != 0)
					{
						ex.health -= 1;

					}
				}
				if (p.getRect().intersects(ex.getRect()))
				{
					if (ex.health != 0)
					{
						if ((p.dy>0) && (p.onGround == false)) { p.dy = -0.2; ex.health -= 5; }
						else {
							p.health -= 1;
							p.sprite.setColor(Color::Red);
						}
					}

				}
				if (p.getRect().intersects(ei.getRect()))
				{
					p.health -= 1;
					p.sprite.setColor(Color::Red);
				}
				if (p.getRect().intersects(en.getRect()))
				{
					p.health -= 1;
					p.sprite.setColor(Color::Red);
				}
				if (ex.life == true)
				{
					window.draw(ex.sprite);
				}
				else
				{
					p.playerScore = 600;
				}

				std::ostringstream bosshealth;
				bosshealth << ex.health;
				text.setString("Score: " + playerscore.str() + "\nHealth:" + playerHealthString.str() + "\nBossHealth:" + bosshealth.str() + "\nGame Time: " + gameTimeString.str() + "\nFrames: " + fra.str());

			}
		}
		
		if (p.playerScore == 600)
		{
			window.clear(Color::White);
			win.setPosition(view.getCenter().x - 220, view.getCenter().y - 50);
			window.draw(win);
			ex.life = false;
		}
		if (p.life == true || p.playerScore < 600)
		{
			text.setPosition(view.getCenter().x - 165, view.getCenter().y - 200);
			window.draw(text);
		}
		/*Condition to check if life is 0 than Losing Screen will be displayed*/
		if (p.health <= 0)
		{
			window.clear(Color::Black);
			s.setPosition(view.getCenter().x - 220, view.getCenter().y - 100);
			window.draw(s);
		}
		p.Draw(window);
		window.display();
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			sf::RenderWindow windowx(sf::VideoMode(800, 580), "Ninja VS The World");
			pause(windowx);
			de = true;
		}
		else { de = false; }
	}

	return 0;
}
