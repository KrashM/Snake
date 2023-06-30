#include "../headers/Snake.hpp"

namespace SnakeGame{

    Snake &Snake::Instance(){

        static Snake instance;
        return instance;

    }

    Snake::Snake(){
        body.push_front(SDL_Point{static_cast<int32_t>(GRID_WIDTH / 2), static_cast<int32_t>(GRID_HEIGHT / 2)});
    }

    void Snake::Update(){

        moved += speed;
        if(moved < 1) return;

        moved = 0.0f;
        direction = direction_change;

        switch(direction){

            case Direction::UP:
                body.push_front(SDL_Point{body.front().x, body.front().y - 1});
                break;

            case Direction::DOWN:
                body.push_front(SDL_Point{body.front().x, body.front().y + 1});
                break;

            case Direction::LEFT:
                body.push_front(SDL_Point{body.front().x - 1, body.front().y});
                break;

            case Direction::RIGHT:
                body.push_front(SDL_Point{body.front().x + 1, body.front().y});
                break;

        }

        if(!growing) body.pop_back();
        else{
            
            if(speed < 1.0f) speed += 0.002f;
            growing = false;

        }

        if(ColidedWithBody() || ColidedWithWall()) alive = false;

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

    std::list<SDL_Point> const &Snake::GetBody() const{
        return body;
    }

    SDL_Point Snake::GetHeadPos() const{
        return body.front();
    }

    std::size_t Snake::Size() const{
        return body.size();
    }

    bool Snake::IsAlive() const{
        return alive;
    }
    
    bool Snake::ColidedWithBody() const{

        for(std::list<SDL_Point>::const_iterator iter = ++body.begin(); iter != body.end(); ++iter)
            if(iter -> x == body.front().x && iter -> y == body.front().y)
                return true;

        return false;

    }

    bool Snake::ColidedWithWall() const{
        return body.front().x < 0 || body.front().x >= GRID_WIDTH || body.front().y < 0 || body.front().y >= GRID_HEIGHT;
    }

}