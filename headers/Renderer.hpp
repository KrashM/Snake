#pragma once

#include "Snake.hpp"
#include <SDL2/SDL_ttf.h>

namespace SnakeGame{

    class Renderer{

    // Singleton Pattern
    public:
        static Renderer &Instance();

    // Remove Public Construction
    private:
        Renderer();

    // Life Cycle
    public:
        Renderer(Renderer const &) = delete;
        Renderer(Renderer &&) = delete;
        ~Renderer();

    // Operators
    public:
        Renderer &operator =(Renderer const &) = delete;
        Renderer &operator =(Renderer &&) = delete;

    // Public Mutators
    public:
        void UpdateWindowTitle(int32_t score, int32_t fps);
        void Render(SDL_Point const food);
        void EndLabel();

    // Private Fields
    private:
        SDL_Renderer *sdl_renderer;
        SDL_Window *sdl_window;
        TTF_Font *font;

    };

}