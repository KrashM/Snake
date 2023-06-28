#include "../headers/Snake.hpp"
#include <cstddef>

namespace SnakeGame{

    Snake::Snake(){
        body.push_back(SDL_Point{GRID_WIDTH / 2, GRID_HEIGHT / 2});
    }

    void Snake::Update(){
        
        switch(direction){

            case Direction::UP:
                body.push_back(SDL_Point{body.back().x, body.back().y - 1});
                break;

            case Direction::DOWN:
                body.push_back(SDL_Point{body.back().x, body.back().y + 1});
                break;

            case Direction::LEFT:
                body.push_back(SDL_Point{body.back().x - 1, body.back().y});
                break;

            case Direction::RIGHT:
                body.push_back(SDL_Point{body.back().x + 1, body.back().y});
                break;

        }

        if(0 < body.back().x || body.back().x >= GRID_WIDTH || body.back().y < 0 || body.back().y >= GRID_HEIGHT){

            alive = false;
            return;

        }

        for(std::size_t i = 0; i < body.size() - 1; ++i)
            if(body[i].x == body.back().x && body[i].y == body.back().y){

                alive = false;
                return;

            }

        if(growing){

            growing = false;
            return;

        }

        body.erase(body.begin());

    }

    void Snake::Grow(){
        growing = true;
    }

    std::size_t Snake::size() const{
        return body.size();
    }

    bool Snake::IsAlive() const{
        return alive;
    }

    bool Snake::Ocupied(int32_t const x, int32_t const y) const{

        for(SDL_Point const cell : body)
            if(cell.x == x && cell.y == y)
                return true;
        return false;

    }

    SDL_Point Snake::GetHeadPos() const{
        return body.back();
    }

    std::vector<SDL_Point> const &Snake::GetBody() const{
        return body;
    }

}