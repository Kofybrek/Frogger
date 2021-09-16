#pragma once

class Car
{
	bool direction;

	short x;

	unsigned char size;
	unsigned char speed;
	unsigned char type;

	unsigned short y;

	sf::Sprite sprite;

	sf::Texture texture;
public:
	Car(unsigned char i_x, unsigned char i_y);

	void draw(sf::RenderWindow& i_window);
	void update();

	sf::IntRect get_rect() const;
};