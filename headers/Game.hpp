#pragma once

#include <random>
#include "Snake.hpp"

namespace SnakeGame{

    class Game{
    
    public:
        Game();
        Game(Game const &) = default;
        Game(Game &&) = default;
        ~Game() = default;

    public:
        Game &operator =(Game const &) = default;
        Game &operator =(Game &&) = default;
    
    public:
        void Run();
        std::size_t GetScore() const;
    
    private:
        void PlaceFood();
        void Update();

    private:
        Snake snake;
        SDL_Point food;
        std::mt19937 engine;
        std::random_device dev;
        std::uniform_int_distribution<int32_t> random_w, random_h;

    };

}