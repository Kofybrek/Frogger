#include <array>
#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Headers/Frog.hpp"
#include "Headers/Global.hpp"
#include "Headers/Log.hpp"
#include "Headers/Turtle.hpp"
#include "Headers/RiverManager.hpp"

RiverManager::RiverManager(unsigned char i_level)
{
	generate_level(i_level);
}

void RiverManager::draw(sf::RenderWindow& i_window)
{
	for (Log& log : logs)
	{
		log.draw(i_window);
	}

	for (Turtle& turtle : turtles)
	{
		turtle.draw(i_window);
	}
}

void RiverManager::generate_level(unsigned char i_level)
{
	logs.clear();

	turtles.clear();

	//I just put in random numbers until I got a nice level.
	switch (i_level)
	{
		case 0:
		{
			logs.push_back(Log(1, 1, 0));
			logs.push_back(Log(3, 9, 0));
			logs.push_back(Log(1, 20, 0));

			turtles.push_back(Turtle(0, 3, 0, 1));
			turtles.push_back(Turtle(0, 3, 4, 1));
			turtles.push_back(Turtle(1, 3, 9, 1));
			turtles.push_back(Turtle(0, 3, 15, 1));

			logs.push_back(Log(2, 2, 2));
			logs.push_back(Log(2, 16, 2));

			logs.push_back(Log(1, 3, 3));
			logs.push_back(Log(1, 8, 3));
			logs.push_back(Log(1, 13, 3));

			turtles.push_back(Turtle(0, 4, 0, 4));
			turtles.push_back(Turtle(0, 4, 6, 4));
			turtles.push_back(Turtle(1, 4, 12, 4));

			break;
		}
		case 1:
		{
			logs.push_back(Log(1, 0, 0));
			logs.push_back(Log(1, 5, 0));
			logs.push_back(Log(1, 10, 0));

			turtles.push_back(Turtle(0, 3, 0, 1));
			turtles.push_back(Turtle(1, 3, 5, 1));
			turtles.push_back(Turtle(0, 3, 10, 1));
			turtles.push_back(Turtle(0, 3, 15, 1));

			logs.push_back(Log(2, 0, 2));
			logs.push_back(Log(2, 8, 2));
			logs.push_back(Log(2, 16, 2));

			logs.push_back(Log(0, 0, 3));
			logs.push_back(Log(0, 4, 3));
			logs.push_back(Log(0, 8, 3));

			turtles.push_back(Turtle(0, 4, 0, 4));
			turtles.push_back(Turtle(0, 4, 5, 4));
			turtles.push_back(Turtle(1, 4, 10, 4));
			turtles.push_back(Turtle(0, 4, 15, 4));

			break;
		}
		case 2:
		{
			logs.push_back(Log(1, 3, 0));
			logs.push_back(Log(1, 8, 0));
			logs.push_back(Log(1, 15, 0));
			logs.push_back(Log(3, 20, 0));

			turtles.push_back(Turtle(1, 3, 0, 1));
			turtles.push_back(Turtle(0, 3, 5, 1));
			turtles.push_back(Turtle(0, 3, 10, 1));
			turtles.push_back(Turtle(0, 3, 19, 1));

			logs.push_back(Log(2, 0, 2));
			logs.push_back(Log(2, 13, 2));

			logs.push_back(Log(1, 1, 3));
			logs.push_back(Log(0, 8, 3));
			logs.push_back(Log(0, 16, 3));

			turtles.push_back(Turtle(1, 4, 0, 4));
			turtles.push_back(Turtle(0, 4, 7, 4));
			turtles.push_back(Turtle(0, 4, 16, 4));

			break;
		}
		case 3:
		{
			logs.push_back(Log(3, 3, 0));
			logs.push_back(Log(2, 15, 0));

			turtles.push_back(Turtle(1, 3, 2, 1));
			turtles.push_back(Turtle(0, 2, 7, 1));
			turtles.push_back(Turtle(0, 4, 14, 1));

			logs.push_back(Log(0, 1, 2));
			logs.push_back(Log(2, 5, 2));
			logs.push_back(Log(1, 13, 2));

			logs.push_back(Log(0, 2, 3));
			logs.push_back(Log(2, 6, 3));
			logs.push_back(Log(0, 15, 3));

			turtles.push_back(Turtle(1, 4, 3, 4));
			turtles.push_back(Turtle(0, 4, 10, 4));

			break;
		}
		case 4:
		{
			logs.push_back(Log(1, 1, 0));
			logs.push_back(Log(1, 8, 0));
			logs.push_back(Log(3, 17, 0));

			turtles.push_back(Turtle(0, 2, 0, 1));
			turtles.push_back(Turtle(0, 3, 5, 1));
			turtles.push_back(Turtle(1, 2, 11, 1));
			turtles.push_back(Turtle(0, 3, 16, 1));

			logs.push_back(Log(2, 2, 2));
			logs.push_back(Log(2, 18, 2));

			logs.push_back(Log(0, 0, 3));
			logs.push_back(Log(0, 7, 3));
			logs.push_back(Log(0, 18, 3));

			turtles.push_back(Turtle(1, 3, 0, 4));
			turtles.push_back(Turtle(0, 3, 6, 4));
			turtles.push_back(Turtle(0, 4, 18, 4));

			break;
		}
		case 5:
		{
			logs.push_back(Log(1, 0, 0));
			logs.push_back(Log(1, 7, 0));
			logs.push_back(Log(3, 15, 0));

			turtles.push_back(Turtle(0, 2, 1, 1));
			turtles.push_back(Turtle(0, 3, 6, 1));
			turtles.push_back(Turtle(1, 2, 12, 1));
			turtles.push_back(Turtle(0, 3, 17, 1));

			logs.push_back(Log(1, 0, 2));
			logs.push_back(Log(2, 7, 2));
			logs.push_back(Log(2, 16, 2));

			logs.push_back(Log(0, 1, 3));
			logs.push_back(Log(0, 8, 3));
			logs.push_back(Log(0, 17, 3));

			turtles.push_back(Turtle(0, 2, 0, 4));
			turtles.push_back(Turtle(0, 3, 6, 4));
			turtles.push_back(Turtle(1, 4, 18, 4));

			break;
		}
		case 6:
		{
			logs.push_back(Log(1, 0, 0));
			logs.push_back(Log(3, 16, 0));

			turtles.push_back(Turtle(1, 4, 0, 1));
			turtles.push_back(Turtle(0, 3, 7, 1));
			turtles.push_back(Turtle(1, 2, 12, 1));
			turtles.push_back(Turtle(0, 2, 18, 1));

			logs.push_back(Log(1, 1, 2));
			logs.push_back(Log(1, 8, 2));
			logs.push_back(Log(2, 15, 2));

			logs.push_back(Log(0, 1, 3));
			logs.push_back(Log(0, 8, 3));
			logs.push_back(Log(0, 17, 3));

			turtles.push_back(Turtle(0, 2, 0, 4));
			turtles.push_back(Turtle(1, 3, 6, 4));
			turtles.push_back(Turtle(0, 3, 18, 4));

			break;
		}
		case 7:
		{
			logs.push_back(Log(3, 3, 0));
			logs.push_back(Log(3, 13, 0));

			turtles.push_back(Turtle(1, 3, 0, 1));
			turtles.push_back(Turtle(0, 2, 8, 1));
			turtles.push_back(Turtle(1, 2, 13, 1));

			logs.push_back(Log(0, 0, 2));
			logs.push_back(Log(1, 6, 2));
			logs.push_back(Log(1, 14, 2));

			logs.push_back(Log(0, 1, 3));
			logs.push_back(Log(0, 10, 3));

			turtles.push_back(Turtle(1, 2, 1, 4));
			turtles.push_back(Turtle(1, 3, 8, 4));
			turtles.push_back(Turtle(0, 2, 19, 4));
		}
	}
}

void RiverManager::update(Frog& i_frog)
{
	bool frog_on_top = 0;

	for (Log& log : logs)
	{
		if (0 == frog_on_top && 0 == i_frog.get_dead())
		{
			frog_on_top = log.check_frog(i_frog);

			log.update(frog_on_top, i_frog);
		}
		else
		{
			log.update(0, i_frog);
		}
	}

	for (Turtle& turtle : turtles)
	{
		if (0 == frog_on_top && 0 == i_frog.get_dead())
		{
			frog_on_top = turtle.check_frog(i_frog);

			turtle.update(frog_on_top, i_frog);
		}
		else
		{
			turtle.update(0, i_frog);
		}
	}

	if (0 == frog_on_top && CELL_SIZE < i_frog.get_y() && i_frog.get_y() < CELL_SIZE * floor(0.5f * MAP_HEIGHT))
	{
		i_frog.set_dead();
	}
}