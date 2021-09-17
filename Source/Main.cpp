#include <array>
#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Headers/Car.hpp"
#include "Headers/Frog.hpp"
#include "Headers/CarsManager.hpp"
#include "Headers/DrawMap.hpp"
#include "Headers/DrawText.hpp"
#include "Headers/Global.hpp"
#include "Headers/Log.hpp"
#include "Headers/Turtle.hpp"
#include "Headers/RiverManager.hpp"

int main()
{
	//Are we showing the next level transition?
	bool next_level = 0;

	unsigned char level = 0;

	unsigned short timer = TIMER_INITIAL_DURATION;
	unsigned short timer_duration = TIMER_INITIAL_DURATION;

	std::array<bool, 5> swamp = {0};

	std::chrono::microseconds lag(0);

	std::chrono::steady_clock::time_point previous_time;

	sf::Event event;

	sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, SCREEN_RESIZE * (FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)), "Frogger", sf::Style::Close);
	window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));

	CarsManager cars_manager(level);

	Frog frog;

	RiverManager river_manager(level);

	previous_time = std::chrono::steady_clock::now();

	while (1 == window.isOpen())
	{
		std::chrono::microseconds delta_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previous_time);

		lag += delta_time;

		previous_time += delta_time;

		while (FRAME_DURATION <= lag)
		{
			lag -= FRAME_DURATION;

			while (1 == window.pollEvent(event))
			{
				switch (event.type)
				{
					case sf::Event::Closed:
					{
						window.close();
					}
				}
			}

			if (1 == next_level)
			{
				if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					next_level = 0;
				}
			}
			else
			{
				if (0 == frog.get_dead())
				{
					if (0 == timer)
					{
						frog.set_dead();
					}
					else
					{
						timer--;
					}
				}

				frog.update();

				cars_manager.update(frog);

				river_manager.update(frog);
			}

			if (1 == frog.get_dead())
			{
				if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					level = 0;

					timer = TIMER_INITIAL_DURATION;
					timer_duration = TIMER_INITIAL_DURATION;

					swamp.fill(0);

					cars_manager.generate_level(level);

					river_manager.generate_level(level);

					frog.reset();
				}
			}
			else if (1 == frog.update_swamp(swamp))
			{
				bool swamp_full = 1;

				for (unsigned char a = 0; a < swamp.size(); a++)
				{
					if (0 == swamp[a])
					{
						swamp_full = 0;

						break;
					}
				}

				if (1 == swamp_full)
				{
					next_level = 1;

					level++;

					//To make sure the timer duration doesn't turn into 1 millisecond, we will not reduce it after reaching a certain limit.
					timer_duration = std::max<unsigned short>(floor(0.25f * TIMER_INITIAL_DURATION), timer_duration - TIMER_REDUCTION);
					timer = timer_duration;

					if (TOTAL_LEVELS == level)
					{
						level = static_cast<unsigned char>(floor(0.5f * TOTAL_LEVELS));
					}

					swamp.fill(0);

					cars_manager.generate_level(level);

					river_manager.generate_level(level);
				}
				else
				{
					timer = std::min<unsigned short>(timer_duration, timer + floor(0.5f * timer_duration));
				}

				frog.reset();
			}

			if (FRAME_DURATION > lag)
			{
				window.clear();

				if (1 == next_level)
				{
					draw_text(1, 0, 0, "NEXT LEVEL!", window);
				}
				else
				{
					draw_map(swamp, window);

					if (0 == frog.get_dead())
					{
						river_manager.draw(window);

						frog.draw(window);
					}
					else
					{
						frog.draw(window);

						river_manager.draw(window);
					}

					cars_manager.draw(window);

					draw_text(0, 0, CELL_SIZE * MAP_HEIGHT, "Time: " + std::to_string(static_cast<unsigned short>(floor(timer / 64.f))), window);
				}

				window.display();
			}
		}
	}
}