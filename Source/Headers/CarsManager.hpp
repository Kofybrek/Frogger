#pragma once

class CarsManager
{
	std::vector<Car> cars;
public:
	CarsManager(unsigned char i_level);

	void draw(sf::RenderWindow& i_window);
	void generate_level(unsigned char i_level);
	void update(Frog& i_frog);
};