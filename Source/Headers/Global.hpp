#pragma once

constexpr unsigned char CELL_SIZE = 16;
//This means "after 32 frames show the next frame of the animation".
constexpr unsigned char CROCODILE_ANIMATION_SPEED = 32;
//I didn't wanna make separate constants for turtles, crocodiles, logs and cars, so I decided to make them universal.
constexpr unsigned char FAST_SPEED = 3;
constexpr unsigned char FONT_HEIGHT = 16;
constexpr unsigned char FROG_ANIMATION_SPEED = 8;
constexpr unsigned char MAP_WIDTH = 16;
constexpr unsigned char MAP_HEIGHT = 15;
constexpr unsigned char NORMAL_SPEED = 2;
constexpr unsigned char SCREEN_RESIZE = 2;
constexpr unsigned char SLOW_SPEED = 1;
constexpr unsigned char TOTAL_LEVELS = 8;
constexpr unsigned char TURTLE_ANIMATION_SPEED = 16;
//Turtles have 4 diving states. And each state last 32 frames.
constexpr unsigned char TURTLE_DIVING_SPEED = 32;

//This is in frames.
constexpr unsigned short TIMER_INITIAL_DURATION = 4096;
//After the player passes the level, we reduce the duration of the timer by this amount.
constexpr unsigned short TIMER_REDUCTION = 512;

constexpr std::chrono::microseconds FRAME_DURATION(16667);