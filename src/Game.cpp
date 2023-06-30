#include "../headers/Game.hpp"

namespace SnakeGame{

    Game &Game::Instance(){

        static Game instance;
        return instance;

    }

    Game::Game(): engine(dev()), random_w(0, GRID_WIDTH - 1), random_h(0, GRID_HEIGHT - 1){
        PlaceFood();
    }

    std::size_t Game::GetScore() const{
        return Snake::Instance().Size();
    }

    void Game::Run(){

        uint32_t title_timestamp = SDL_GetTicks(), frame_start, frame_end, frame_duration, frame_count = 0;
        bool running = true;
        Renderer::Instance();

        while(running){

            frame_start = SDL_GetTicks();

            Controller::Instance().HandleInput(running);
            Renderer::Instance().Render(food);
            Update();

            frame_end = SDL_GetTicks();

            frame_count++;
            frame_duration = frame_end - frame_start;

            if(frame_end - title_timestamp >= 1000){

                Renderer::Instance().UpdateWindowTitle(Snake::Instance().Size(), frame_count);
                frame_count = 0;
                title_timestamp = frame_end;

            }

            if(frame_duration < MS_PER_FRAME) SDL_Delay(MS_PER_FRAME - frame_duration);

        }

    }

    void Game::PlaceFood(){

        if(occupied_squares == GRID_HEIGHT * GRID_WIDTH) return;

        int32_t x, y;

        do{

            x = static_cast<int32_t>(random_w(engine));
            y = static_cast<int32_t>(random_h(engine));

        }while(Snake::Instance().Ocupied(x, y));

        food.x = x;
        food.y = y;

    }

    void Game::Update(){

        Snake &snake = Snake::Instance();

        if(!snake.IsAlive()) return;
        snake.Update();

        if(food.x == snake.GetHeadPos().x && food.y == snake.GetHeadPos().y){

            PlaceFood();
            snake.Grow();
            ++occupied_squares;

        }

    }

}