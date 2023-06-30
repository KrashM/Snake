#pragma once

#include <random>
#include "Snake.hpp"
#include "Renderer.hpp"
#include "Controller.hpp"

namespace SnakeGame{

    class Game{

    // Singleton Pattern
    public:
        static Game &Instance();

    // Remove Public Construction
    private:
        Game();

    // Life Cycle
    public:
        Game(Game const &) = default;
        Game(Game &&) = default;
        ~Game() = default;

    // Operators
    public:
        Game &operator =(Game const &) = default;
        Game &operator =(Game &&) = default;
    
    // Public Mutators
    public:
        std::size_t GetScore() const;
        void Run();
    
    // Private Mutators
    private:
        void PlaceFood();
        void Update();

    // Private Fields
    private:
        SDL_Point food;
        std::size_t occupied_squares = 1;
        std::random_device dev;
        std::mt19937 engine;
        std::uniform_int_distribution<std::size_t> random_w, random_h;

    };

}