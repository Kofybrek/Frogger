#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Headers/Car.hpp"
#include "Headers/Global.hpp"

Car::Car(unsigned char i_x, unsigned char i_y) :
	direction(i_y % 2),
	x(CELL_SIZE * i_x),
	size(CELL_SIZE * (1 + (2 > i_y))),
	type(i_y),
	y(static_cast<unsigned short>(CELL_SIZE * floor(1 + i_y + 0.5f * MAP_HEIGHT)))
{
	//We're using warping here in case we generated this car outside of the map.
	if (0 == direction)
	{
		if (x >= CELL_SIZE * MAP_WIDTH)
		{
			x -= static_cast<short>(CELL_SIZE * floor(1.5f * MAP_WIDTH));
		}
	}
	else
	{
		if (x <= -CELL_SIZE * floor(0.5f * MAP_WIDTH))
		{
			x += static_cast<short>(CELL_SIZE * floor(1.5f * MAP_WIDTH));
		}
	}

	if (2 > i_y)
	{
		speed = NORMAL_SPEED;
	}
	else if (4 > i_y)
	{
		speed = FAST_SPEED;
	}
	else
	{
		speed = SLOW_SPEED;
	}
}

void Car::draw(sf::RenderWindow& i_window)
{
	texture.loadFromFile("Resources/Images/Cars.png");

	sprite.setPosition(x, y);
	sprite.setTexture(texture);

	if (0 == direction)
	{
		sprite.setTextureRect(sf::IntRect(0, CELL_SIZE * type, size, CELL_SIZE));
	}
	else
	{
		//I drew the cars facing right. If the car is moving to the left, we read the texture from right to left, thus making it mirrored.
		sprite.setTextureRect(sf::IntRect(size, CELL_SIZE * type, -size, CELL_SIZE));
	}
	
	i_window.draw(sprite);
}

void Car::update()
{
	if (0 == direction)
	{
		x += speed;

		if (x >= CELL_SIZE * MAP_WIDTH)
		{
			x -= static_cast<short>(CELL_SIZE * floor(1.5f * MAP_WIDTH));
		}
	}
	else
	{
		x -= speed;

		if (x <= -CELL_SIZE * floor(0.5f * MAP_WIDTH))
		{
			x += static_cast<short>(CELL_SIZE * floor(1.5f * MAP_WIDTH));
		}
	}
}

sf::IntRect Car::get_rect() const
{
	return sf::IntRect(x, y, size, CELL_SIZE);
}