#pragma once

class RiverManager
{
	std::vector<Log> logs;

	std::vector<Turtle> turtles;
public:
	RiverManager(unsigned char i_level);

	void draw(sf::RenderWindow& i_window);
	void generate_level(unsigned char i_level);
	void update(Frog& i_frog);
};