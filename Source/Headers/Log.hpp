#pragma once

class Log
{
	bool direction;

	short x;

	unsigned char animation_timer;
	unsigned char current_frame;
	unsigned char size;
	unsigned char speed;
	unsigned char type;

	unsigned short y;

	sf::Sprite sprite;

	sf::Texture texture;
public:
	Log(unsigned char i_type, unsigned char i_x, unsigned char i_y);

	bool check_frog(const Frog& i_frog) const;

	void draw(sf::RenderWindow& i_window);
	void update(bool i_move_frog, Frog& i_frog);
};