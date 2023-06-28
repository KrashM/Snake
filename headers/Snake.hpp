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
        Snake(Snake const &) = default;
        Snake(Snake &&) = default;
        ~Snake() = default;

    // Operators
    public:
        Snake &operator =(Snake const &) = default;
        Snake &operator =(Snake &&) = default;
    
    // Mutators
    public:
        void Update();
        void Grow();
    
    // Information
    public:
        bool IsAlive() const;
        std::size_t size() const;
        bool Ocupied(int32_t const x, int32_t const y) const;
        SDL_Point GetHeadPos() const;
        std::vector<SDL_Point> const &GetBody() const;

    // Fields
    private:
        std::vector<SDL_Point> body;
        Direction direction = Direction::UP;
        bool alive = true, growing = false;

    };

}