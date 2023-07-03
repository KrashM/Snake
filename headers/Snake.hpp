#pragma once

#include "Globals.hpp"
#include <SDL2/SDL.h>
#include <cstddef>
#include <list>

namespace SnakeGame{

    class Snake{

    // Singleton Pattern
    public:
        static Snake &Instance();

    // Remove Public Construction
    private:
        Snake();

    // Life Cycle
    public:
        Snake(Snake const &) = delete;
        Snake(Snake &&) = delete;
        ~Snake() = default;

    // Operators
    public:
        Snake &operator =(Snake const &) = delete;
        Snake &operator =(Snake &&) = delete;
    
    // Mutators
    public:
        void Restart();
        void Update();
        void Grow();
    
    // Information
    public:
        bool Ocupied(int32_t const x, int32_t const y) const;
        std::list<SDL_Point> const &GetBody() const;
        SDL_Point GetHeadPos() const;
        std::size_t Size() const;
        bool IsAlive() const;

    // Private Information
    private:
        bool ColidedWithBody() const;
        bool ColidedWithWall() const;
        void Initialize();

    // Public fields
    public:
        Direction direction = Direction::UP;
        Direction direction_change;

    // Private Fields
    private:
        std::list<SDL_Point> body;
        bool alive = true, growing = false;
        float moved = 0.0f, speed = 0.1f;

    };

}