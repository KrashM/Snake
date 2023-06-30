#pragma once

#include <vector>
#include <cstddef>
#include <SDL2/SDL.h>
#include "Globals.hpp"

namespace SnakeGame{

    class Snake{

    // Life Cycle
    public:
        Snake();
        Snake(Snake const &) = delete;
        Snake(Snake &&) = delete;
        ~Snake() = default;

    // Operators
    public:
        Snake &operator =(Snake const &) = delete;
        Snake &operator =(Snake &&) = delete;
    
    // Mutators
    public:
        void Update();
        void Grow();
    
    // Information
    public:
        bool Ocupied(int32_t const x, int32_t const y) const;
        std::vector<SDL_Point> const &GetBody() const;
        SDL_Point GetHeadPos() const;
        std::size_t size() const;
        bool IsAlive() const;

    // Public fields
    public:
        Direction direction = Direction::UP;
        Direction direction_change;

    // Private Fields
    private:
        std::vector<SDL_Point> body;
        bool alive = true, growing = false;
        float moved = 0.0f;

    };

}