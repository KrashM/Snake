#include "../headers/Snake.hpp"

namespace SnakeGame{

    Snake::Snake(){
        body.push_back(SDL_Point{static_cast<int32_t>(GRID_WIDTH / 2), static_cast<int32_t>(GRID_HEIGHT / 2)});
    }

    void Snake::Update(){

        moved += 0.1f;
        if(moved < 1) return;

        moved = 0.0f;
        direction = direction_change;

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

        if(!growing) body.erase(body.begin());
        else growing = false;

        if(body.back().x < 0 || body.back().x >= GRID_WIDTH || body.back().y < 0 || body.back().y >= GRID_HEIGHT){

            alive = false;
            return;

        }

        for(std::size_t i = 0; i < body.size() - 1; ++i)
            if(body[i].x == body.back().x && body[i].y == body.back().y){

                alive = false;
                return;

            }

    }

    void Snake::Grow(){
        growing = true;
    }

    bool Snake::Ocupied(int32_t const x, int32_t const y) const{

        for(SDL_Point const cell : body)
            if(cell.x == x && cell.y == y)
                return true;
        return false;

    }

    std::vector<SDL_Point> const &Snake::GetBody() const{
        return body;
    }

    SDL_Point Snake::GetHeadPos() const{
        return body.back();
    }

    std::size_t Snake::size() const{
        return body.size();
    }

    bool Snake::IsAlive() const{
        return alive;
    }

}