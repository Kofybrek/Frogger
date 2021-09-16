#pragma once

class Frog
{
	bool dead;

	short x;

	unsigned char animation_timer;
	unsigned char current_frame;
	//The current direction the frog is facing.
	unsigned char direction;

	unsigned short y;

	//The previous state of the arrow keys. (Pressed or not pressed)
	//We'll use it to move the frog only once.
	std::array<bool, 4> control_keys;

	sf::Sprite sprite;

	sf::Texture texture;
public:
	Frog();

	bool get_dead() const;

	bool update_swamp(std::array<bool, 5>& i_swamp);

	unsigned short get_y() const;

	void draw(sf::RenderWindow& i_window);
	void move(char i_value);
	void reset();
	void set_dead();
	void update();

	sf::IntRect get_rect() const;
};