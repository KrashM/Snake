#include "../headers/Controller.hpp"

namespace SnakeGame{
    
    Controller &Controller::Instance(){

        static Controller instance;
        return instance;

    }

    void Controller::HandleInput(bool &running) const{

        SDL_Event e;

        while(SDL_PollEvent(&e)){

            if(e.type == SDL_QUIT) running = false;
            else if(e.type == SDL_KEYDOWN)
                switch(e.key.keysym.sym){

                    case SDLK_UP:
                        ChangeDirection(Direction::UP, Direction::DOWN);
                        break;

                    case SDLK_DOWN:
                        ChangeDirection(Direction::DOWN, Direction::UP);
                        break;

                    case SDLK_LEFT:
                        ChangeDirection(Direction::LEFT, Direction::RIGHT);
                        break;

                    case SDLK_RIGHT:
                        ChangeDirection(Direction::RIGHT, Direction::LEFT);
                        break;

                }

        }

    }

    void Controller::ChangeDirection(Direction input, Direction opposite) const{

        if(Snake::Instance().direction != opposite || Snake::Instance().Size() == 1) Snake::Instance().direction_change = input;
        return;

    }

}
