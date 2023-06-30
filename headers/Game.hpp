#pragma once

#include <random>
#include "Snake.hpp"
#include "Renderer.hpp"
#include "Controller.hpp"

namespace SnakeGame{

    class Game{
    
    // Life Cycle
    public:
        Game();
        Game(Game const &) = default;
        Game(Game &&) = default;
        ~Game() = default;

    // Operators
    public:
        Game &operator =(Game const &) = default;
        Game &operator =(Game &&) = default;
    
    // Public Mutators
    public:
        void Run(Controller const &controller, Renderer &renderer);
        std::size_t GetScore() const;
    
    // Private Mutators
    private:
        void PlaceFood();
        void Update();

    // Private Fields
    private:
        Snake snake;
        SDL_Point food;
        std::random_device dev;
        std::mt19937 engine;
        std::uniform_int_distribution<std::size_t> random_w, random_h;

    };

}