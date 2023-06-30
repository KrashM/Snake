#include "../headers/Renderer.hpp"
#include <iostream>
#include <string>

namespace SnakeGame{

    Renderer::Renderer(){

        if(SDL_Init(SDL_INIT_VIDEO) < 0){

            std::cerr << "SDL could not initialize.\n";
            std::cerr << "SDL_Error: " << SDL_GetError() << '\n';

        }

        sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
                                        WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

        if(!sdl_window){

            std::cerr << "Window could not be created.\n";
            std::cerr << " SDL_Error: " << SDL_GetError() << '\n';

        }

        sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);

        if(!sdl_renderer){

            std::cerr << "Renderer could not be created.\n";
            std::cerr << "SDL_Error: " << SDL_GetError() << '\n';

        }

    }

    Renderer::~Renderer(){

        SDL_DestroyWindow(sdl_window);
        SDL_Quit();

    }

    void Renderer::Render(Snake const &snake, SDL_Point const food){

        SDL_Rect block;
        block.w = static_cast<int32_t>(WINDOW_WIDTH / GRID_WIDTH);
        block.h = static_cast<int32_t>(WINDOW_HEIGHT / GRID_HEIGHT);

        SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
        SDL_RenderClear(sdl_renderer);

        SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
        block.x = food.x * block.w;
        block.y = food.y * block.h;
        SDL_RenderFillRect(sdl_renderer, &block);

        SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        for(SDL_Point const &point : snake.GetBody()){

            block.x = point.x * block.w;
            block.y = point.y * block.h;
            SDL_RenderFillRect(sdl_renderer, &block);

        }

        block.x = snake.GetHeadPos().x * block.w;
        block.y = snake.GetHeadPos().y * block.h;

        if(snake.IsAlive()) SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
        else SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);

        SDL_RenderFillRect(sdl_renderer, &block);
        SDL_RenderPresent(sdl_renderer);

    }

    void Renderer::UpdateWindowTitle(int32_t const score, int32_t const fps){

        std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
        SDL_SetWindowTitle(sdl_window, title.c_str());

    }

}