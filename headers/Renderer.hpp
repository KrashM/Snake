#pragma once

#include <cstddef>
#include "Snake.hpp"

namespace SnakeGame{

    class Renderer{

    public:
        Renderer();
        Renderer(Renderer const &) = delete;
        Renderer(Renderer &&) = delete;
        ~Renderer();

    public:
        Renderer &operator =(Renderer const &) = delete;
        Renderer &operator =(Renderer &&) = delete;

    public:
        void Render(Snake const &snake, SDL_Point const food);
        void UpdateWindowTitle(int32_t score, int32_t fps);

    private:
        SDL_Window *sdl_window;
        SDL_Renderer *sdl_renderer;

    };

}