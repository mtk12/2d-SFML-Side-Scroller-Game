#pragma once
#include<SFML\Graphics.hpp>

using namespace sf;

void pause(RenderWindow & window) {
	Texture menuTexturel, menuTexture1, menuTexture2;
	menuTexturel.loadFromFile("ImageAssets/bg1.png");
	menuTexture1.loadFromFile("ImageAssets/r.png");
	menuTexture2.loadFromFile("ImageAssets/p.png");
	Sprite menul(menuTexturel), menu1(menuTexture1), menu2(menuTexture2);
	bool isMenu = 1;
	int menunum = 0;
	menul.setPosition(0, 0);
	menu1.setPosition(300, 300);
	menu2.setPosition(220, 90);
	

	Event event;

	while (isMenu)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		menu1.setColor(Color::White);
		window.clear(Color(129, 181, 221));

		if (IntRect(300, 300, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Color::Cyan); menunum = 1; }
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menunum == 1) { isMenu = false; }

		}
		if (Keyboard::isKeyPressed(Keyboard::C))
		{
			isMenu = false;
		}

		window.draw(menul);
		window.draw(menu1);
		window.draw(menu2);
		window.display();

	}
}
