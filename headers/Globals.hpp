#pragma once

#include <cstdint>

namespace SnakeGame{

    enum class Direction{
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    int32_t const GRID_WIDTH = 20;
    int32_t const GRID_HEIGHT = 20;
    int32_t const WINDOW_WIDTH = 800;
    int32_t const WINDOW_HEIGHT = 600;

}