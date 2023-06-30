#include "Snake.hpp"

namespace SnakeGame{

    class Controller{

    // Public Interface
    public:
        void HandleInput(bool &running, Snake &snake) const;

    // Private Interface
    private:
        void ChangeDirection(Snake &snake, Direction input, Direction opposite) const;

    };

}