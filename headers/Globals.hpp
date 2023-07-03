#pragma once

#include <cstdint>
#include <cstddef>
#include <iostream>

namespace SnakeGame{

    enum class Direction{
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    std::size_t const GRID_WIDTH = 32;
    std::size_t const GRID_HEIGHT = 32;
    std::size_t const WINDOW_WIDTH = 800;
    std::size_t const WINDOW_HEIGHT = 800;
    std::size_t const FRAMES_PER_SECOND = 60;
    std::size_t const MS_PER_FRAME = 1000 / FRAMES_PER_SECOND;

    std::size_t const FONT_SIZE = 24;
    char const * const FONT_NAME = "resources/fonts/Belanosima-Regular.ttf";

}