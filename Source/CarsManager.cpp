#include <array>
#include <chrono>
#include <SFML/Graphics.hpp>

#include "Headers/Car.hpp"
#include "Headers/Frog.hpp"
#include "Headers/CarsManager.hpp"
#include "Headers/Global.hpp"

CarsManager::CarsManager(unsigned char i_level)
{
	generate_level(i_level);
}

void CarsManager::draw(sf::RenderWindow& i_window)
{
	for (Car& car : cars)
	{
		car.draw(i_window);
	}
}

void CarsManager::generate_level(unsigned char i_level)
{
	cars.clear();

	switch (i_level)
	{
		case 0:
		{
			cars.push_back(Car(1, 0));
			cars.push_back(Car(9, 0));

			cars.push_back(Car(7, 1));
			cars.push_back(Car(11, 1));

			cars.push_back(Car(8, 3));
			cars.push_back(Car(10, 2));

			cars.push_back(Car(2, 3));

			cars.push_back(Car(0, 4));
			cars.push_back(Car(6, 4));
			cars.push_back(Car(13, 4));

			cars.push_back(Car(0, 5));
			cars.push_back(Car(7, 5));
			cars.push_back(Car(14, 5));

			break;
		}
		case 1:
		{
			cars.push_back(Car(1, 0));
			cars.push_back(Car(7, 0));
			cars.push_back(Car(13, 0));

			cars.push_back(Car(4, 1));
			cars.push_back(Car(10, 1));
			cars.push_back(Car(14, 1));

			cars.push_back(Car(9, 2));
			cars.push_back(Car(14, 2));

			cars.push_back(Car(5, 3));
			cars.push_back(Car(7, 3));

			cars.push_back(Car(2, 4));
			cars.push_back(Car(10, 4));
			cars.push_back(Car(15, 4));
			cars.push_back(Car(21, 4));

			cars.push_back(Car(0, 5));
			cars.push_back(Car(4, 5));
			cars.push_back(Car(11, 5));
			cars.push_back(Car(18, 5));

			break;
		}
		case 2:
		{
			cars.push_back(Car(1, 0));
			cars.push_back(Car(5, 0));
			cars.push_back(Car(12, 0));
			cars.push_back(Car(19, 0));

			cars.push_back(Car(4, 1));
			cars.push_back(Car(9, 1));
			cars.push_back(Car(18, 1));

			cars.push_back(Car(2, 2));
			cars.push_back(Car(10, 2));
			cars.push_back(Car(18, 2));

			cars.push_back(Car(4, 3));

			cars.push_back(Car(0, 4));
			cars.push_back(Car(9, 4));
			cars.push_back(Car(13, 4));
			cars.push_back(Car(19, 4));

			cars.push_back(Car(2, 5));
			cars.push_back(Car(6, 5));
			cars.push_back(Car(15, 5));
			cars.push_back(Car(22, 5));

			break;
		}
		case 3:
		{
			cars.push_back(Car(3, 0));
			cars.push_back(Car(10, 0));
			cars.push_back(Car(16, 0));
			cars.push_back(Car(21, 0));

			cars.push_back(Car(2, 1));
			cars.push_back(Car(7, 1));
			cars.push_back(Car(15, 1));

			cars.push_back(Car(1, 2));
			cars.push_back(Car(5, 2));

			cars.push_back(Car(4, 3));
			cars.push_back(Car(13, 3));
			cars.push_back(Car(10, 3));

			cars.push_back(Car(3, 4));
			cars.push_back(Car(6, 4));
			cars.push_back(Car(13, 4));
			cars.push_back(Car(20, 4));

			cars.push_back(Car(1, 5));
			cars.push_back(Car(4, 5));
			cars.push_back(Car(10, 5));
			cars.push_back(Car(16, 5));

			break;
		}
		case 4:
		{
			cars.push_back(Car(0, 0));
			cars.push_back(Car(6, 0));
			cars.push_back(Car(11, 0));
			cars.push_back(Car(21, 0));

			cars.push_back(Car(2, 1));
			cars.push_back(Car(7, 1));
			cars.push_back(Car(16, 1));
			cars.push_back(Car(20, 1));

			cars.push_back(Car(1, 2));
			cars.push_back(Car(9, 2));
			cars.push_back(Car(15, 2));

			cars.push_back(Car(7, 3));
			cars.push_back(Car(13, 3));

			cars.push_back(Car(1, 4));
			cars.push_back(Car(8, 4));
			cars.push_back(Car(12, 4));
			cars.push_back(Car(18, 4));

			cars.push_back(Car(1, 5));
			cars.push_back(Car(8, 5));
			cars.push_back(Car(16, 5));
			cars.push_back(Car(21, 5));

			break;
		}
		case 5:
		{
			cars.push_back(Car(0, 0));
			cars.push_back(Car(4, 0));
			cars.push_back(Car(10, 0));
			cars.push_back(Car(15, 0));

			cars.push_back(Car(1, 1));
			cars.push_back(Car(6, 1));
			cars.push_back(Car(14, 1));
			cars.push_back(Car(18, 1));

			cars.push_back(Car(0, 2));
			cars.push_back(Car(6, 2));

			cars.push_back(Car(7, 3));
			cars.push_back(Car(12, 3));
			cars.push_back(Car(15, 3));

			cars.push_back(Car(0, 4));
			cars.push_back(Car(9, 4));
			cars.push_back(Car(13, 4));
			cars.push_back(Car(20, 4));

			cars.push_back(Car(0, 5));
			cars.push_back(Car(7, 5));
			cars.push_back(Car(15, 5));
			cars.push_back(Car(20, 5));

			break;
		}
		case 6:
		{
			cars.push_back(Car(0, 0));
			cars.push_back(Car(3, 0));
			cars.push_back(Car(8, 0));
			cars.push_back(Car(14, 0));

			cars.push_back(Car(0, 1));
			cars.push_back(Car(7, 1));
			cars.push_back(Car(15, 1));
			cars.push_back(Car(20, 1));

			cars.push_back(Car(1, 2));
			cars.push_back(Car(8, 2));

			cars.push_back(Car(0, 3));
			cars.push_back(Car(10, 3));
			cars.push_back(Car(19, 3));

			cars.push_back(Car(0, 4));
			cars.push_back(Car(7, 4));
			cars.push_back(Car(12, 4));
			cars.push_back(Car(19, 4));
			cars.push_back(Car(21, 4));

			cars.push_back(Car(0, 5));
			cars.push_back(Car(5, 5));
			cars.push_back(Car(16, 5));
			cars.push_back(Car(21, 5));

			break;
		}
		case 7:
		{
			cars.push_back(Car(1, 0));
			cars.push_back(Car(5, 0));
			cars.push_back(Car(8, 0));
			cars.push_back(Car(14, 0));
			cars.push_back(Car(18, 0));

			cars.push_back(Car(0, 1));
			cars.push_back(Car(7, 1));
			cars.push_back(Car(15, 1));
			cars.push_back(Car(20, 1));

			cars.push_back(Car(1, 2));
			cars.push_back(Car(8, 2));
			cars.push_back(Car(15, 2));

			cars.push_back(Car(0, 3));
			cars.push_back(Car(10, 3));
			cars.push_back(Car(19, 3));

			cars.push_back(Car(1, 4));
			cars.push_back(Car(7, 4));
			cars.push_back(Car(11, 4));
			cars.push_back(Car(18, 4));
			cars.push_back(Car(22, 4));

			cars.push_back(Car(0, 5));
			cars.push_back(Car(4, 5));
			cars.push_back(Car(9, 5));
			cars.push_back(Car(16, 5));
			cars.push_back(Car(20, 5));
		}
	}
}

void CarsManager::update(Frog& i_frog)
{
	for (Car& car : cars)
	{
		car.update();
	}

	if (0 == i_frog.get_dead())
	{
		for (Car& car : cars)
		{
			if (1 == car.get_rect().intersects(i_frog.get_rect()))
			{
				i_frog.set_dead();
			}
		}
	}
}