#pragma once

#include "Snake.hpp"

namespace SnakeGame{

    class Renderer{

    // Life Cycle
    public:
        Renderer();
        Renderer(Renderer const &) = delete;
        Renderer(Renderer &&) = delete;
        ~Renderer();

    // Operators
    public:
        Renderer &operator =(Renderer const &) = delete;
        Renderer &operator =(Renderer &&) = delete;

    // Public Mutators
    public:
        void Render(Snake const &snake, SDL_Point const food);
        void UpdateWindowTitle(int32_t score, int32_t fps);

    // Private Fields
    private:
        SDL_Renderer *sdl_renderer;
        SDL_Window *sdl_window;

    };

}