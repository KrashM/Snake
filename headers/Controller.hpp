#include "Snake.hpp"

namespace SnakeGame{

    class Controller{

    // Singleton Pattern
    public:
        static Controller &Instance();

    // Remove Public Construction
    private:
        Controller() = default;
    
    // Life Cycle
    public:
        Controller(Controller const &) = delete;
        Controller(Controller &&) = delete;
        ~Controller() = default;

    // Public Interface
    public:
        void HandleInput(bool &running) const;

    // Private Interface
    private:
        void ChangeDirection(Direction input, Direction opposite) const;

    };

}