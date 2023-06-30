#include "../headers/Game.hpp"

namespace SnakeGame{

    Game::Game(): engine(dev()), random_w(0, GRID_WIDTH - 1), random_h(0, GRID_HEIGHT - 1){
        PlaceFood();
    }

    void Game::Run(Controller const &controller, Renderer &renderer){

        uint32_t title_timestamp = SDL_GetTicks(), frame_start, frame_end, frame_duration;
        int32_t frame_count = 0;
        bool running = true;

        while(running){

            frame_start = SDL_GetTicks();

            controller.HandleInput(running, snake);
            renderer.Render(snake, food);
            Update();

            frame_end = SDL_GetTicks();

            frame_count++;
            frame_duration = frame_end - frame_start;

            if(frame_end - title_timestamp >= 1000){

                renderer.UpdateWindowTitle(snake.size(), frame_count);
                frame_count = 0;
                title_timestamp = frame_end;

            }

            if(frame_duration < MS_PER_FRAME) SDL_Delay(MS_PER_FRAME - frame_duration);

        }

    }

    std::size_t Game::GetScore() const{
        return snake.size();
    }

    void Game::PlaceFood(){

        int32_t x, y;

        do{

            x = static_cast<int32_t>(random_w(engine));
            y = static_cast<int32_t>(random_h(engine));

        }while(snake.Ocupied(x, y));

        food.x = x;
        food.y = y;

    }

    void Game::Update(){

        if(!snake.IsAlive()) return;
        snake.Update();

        if(food.x == snake.GetHeadPos().x && food.y == snake.GetHeadPos().y){

            PlaceFood();
            snake.Grow();

        }

    }

}