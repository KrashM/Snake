#include "../headers/Game.hpp"

namespace SnakeGame{

    Game::Game(): engine(dev()), random_w(0, GRID_WIDTH - 1), random_h(0, GRID_HEIGHT - 1){
        PlaceFood();
    }

    void Game::Run(){
        // 
    }

    std::size_t Game::GetScore() const{
        return snake.size();
    }

    void Game::PlaceFood(){
        
        int32_t x, y;

        do{

            x = random_w(engine);
            y = random_h(engine);

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