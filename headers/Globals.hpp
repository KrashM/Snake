#pragma once

#include <cstdint>
#include <cstddef>

namespace SnakeGame{

    enum class Direction{
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    std::size_t const MS_PER_FRAME = 1000 / FRAMES_PER_SECOND;
    std::size_t const FRAMES_PER_SECOND = 60;
    std::size_t const WINDOW_HEIGHT = 640;
    std::size_t const WINDOW_WIDTH = 640;
    std::size_t const GRID_HEIGHT = 32;
    std::size_t const GRID_WIDTH = 32;

}