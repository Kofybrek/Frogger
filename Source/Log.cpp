#include <array>
#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Headers/Frog.hpp"
#include "Headers/Global.hpp"
#include "Headers/Log.hpp"

Log::Log(unsigned char i_type, unsigned char i_x, unsigned char i_y) :
	direction(i_y % 2),
	x(CELL_SIZE * i_x),
	animation_timer(CROCODILE_ANIMATION_SPEED),
	current_frame(0),
	size(2 * CELL_SIZE * std::min(3, 1 + i_type)),
	type(i_type),
	y(CELL_SIZE * (2 + i_y))
{
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
		speed = SLOW_SPEED;
	}
	else if (4 > i_y)
	{
		speed = NORMAL_SPEED;
	}
	else
	{
		speed = FAST_SPEED;
	}
}

bool Log::check_frog(const Frog& i_frog) const
{
	if (3 > type) //When log is log.
	{
		return i_frog.get_rect().intersects(sf::IntRect(static_cast<short>(x + floor(0.25f * CELL_SIZE)), y, static_cast<short>(size - floor(0.5f * CELL_SIZE)), CELL_SIZE));
	}
	else //When log is crocodile.
	{
		//We'll check the collision by assuming the crocodile is a medium-sized log.
		return i_frog.get_rect().intersects(sf::IntRect(static_cast<short>(x + floor(0.25f * CELL_SIZE)), y, static_cast<short>(size - floor(2.5f * CELL_SIZE)), CELL_SIZE));
	}
}

void Log::draw(sf::RenderWindow& i_window)
{
	texture.loadFromFile("Resources/Images/Logs.png");

	sprite.setPosition(x, y);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(6 * CELL_SIZE * current_frame, CELL_SIZE * type, size, CELL_SIZE));

	//We won't mirror the logs.
	if (1 == direction && 3 == type)
	{
		sprite.setTextureRect(sf::IntRect(size + 6 * CELL_SIZE * current_frame, CELL_SIZE * type, -size, CELL_SIZE));
	}

	i_window.draw(sprite);
}

void Log::update(bool i_move_frog, Frog& i_frog)
{
	if (3 == type)
	{
		if (0 == animation_timer)
		{
			current_frame = (1 + current_frame) % 2;

			animation_timer = CROCODILE_ANIMATION_SPEED;
		}
		else
		{
			animation_timer--;
		}
	}

	if (0 == direction)
	{
		x += speed;

		if (1 == i_move_frog)
		{
			i_frog.move(speed);
		}

		if (x >= CELL_SIZE * MAP_WIDTH)
		{
			x -= static_cast<short>(CELL_SIZE * floor(1.5f * MAP_WIDTH));
		}
	}
	else
	{
		x -= speed;

		if (1 == i_move_frog)
		{
			i_frog.move(-speed);
		}

		if (x <= -CELL_SIZE * floor(0.5f * MAP_WIDTH))
		{
			x += static_cast<short>(CELL_SIZE * floor(1.5f * MAP_WIDTH));
		}
	}
}