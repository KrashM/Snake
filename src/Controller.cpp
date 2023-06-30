#include "../headers/Controller.hpp"

namespace SnakeGame{

    void Controller::HandleInput(bool &running, Snake &snake) const{

        SDL_Event e;
        std::size_t i = 0;

        while(SDL_PollEvent(&e)){

            if(e.type == SDL_QUIT) running = false;
            else if(e.type == SDL_KEYDOWN)
                switch(e.key.keysym.sym){

                    case SDLK_UP:
                        ChangeDirection(snake, Direction::UP, Direction::DOWN);
                        break;

                    case SDLK_DOWN:
                        ChangeDirection(snake, Direction::DOWN, Direction::UP);
                        break;

                    case SDLK_LEFT:
                        ChangeDirection(snake, Direction::LEFT, Direction::RIGHT);
                        break;

                    case SDLK_RIGHT:
                        ChangeDirection(snake, Direction::RIGHT, Direction::LEFT);
                        break;

                }

        }

    }

    void Controller::ChangeDirection(Snake &snake, Direction input, Direction opposite) const{

        if(snake.direction != opposite || snake.size() == 1) snake.direction_change = input;
        return;

    }

}
