#pragma once
#include<SFML\Graphics.hpp>

using namespace sf;

void menu(RenderWindow & window){
	Texture menuTexturel,menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexturel.loadFromFile("ImageAssets/l.png");
	menuTexture1.loadFromFile("ImageAssets/s.png");
	menuTexture2.loadFromFile("ImageAssets/o.png");
	menuTexture3.loadFromFile("ImageAssets/e.png");
	aboutTexture.loadFromFile("ImageAssets/op.png");
	menuBackground.loadFromFile("ImageAssets/bg1.png");
	Sprite menul(menuTexturel),menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture),menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menul.setPosition(250, 90);
	menu1.setPosition(300, 210);
	menu2.setPosition(300, 300);
	menu3.setPosition(300, 390);
	menuBg.setPosition(0, 0);

	Event event;

	while (isMenu)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(300, 210, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Color::Cyan); menuNum = 1; }
		if (IntRect(300, 300, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Color::Cyan); menuNum = 2; }
		if (IntRect(300, 390, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Color::Cyan); menuNum = 3; }
		
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menul);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
		
	}
}
