#include "../headers/Renderer.hpp"
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

namespace SnakeGame{

    Renderer &Renderer::Instance(){

        static Renderer instance;
        return instance;

    }

    Renderer::Renderer(){

        if(SDL_Init(SDL_INIT_VIDEO) < 0){

            std::cerr << "SDL could not initialize.\n";
            std::cerr << "SDL_Error: " << SDL_GetError() << '\n';

        }

        if(TTF_Init() < 0){

            std::cerr << "TTF could not initialize.\n";
            std::cerr << "TTF_Error: " << TTF_GetError() << '\n';

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

        font = TTF_OpenFont(FONT_NAME, FONT_SIZE);

        if(!font){

            std::cerr << "Font could not be found.\n";
            std::cerr << "TTF_Error: " << TTF_GetError() << '\n';

        }

    }

    Renderer::~Renderer(){

        SDL_DestroyRenderer(sdl_renderer);
        SDL_DestroyWindow(sdl_window);
        TTF_CloseFont(font);
        TTF_Quit();
        SDL_Quit();

    }

    void Renderer::UpdateWindowTitle(int32_t const score, int32_t const fps){

        std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
        SDL_SetWindowTitle(sdl_window, title.c_str());

    }

    void Renderer::Render(SDL_Point const food){

        SDL_Rect block;
        block.w = static_cast<int32_t>(WINDOW_WIDTH / GRID_WIDTH);
        block.h = static_cast<int32_t>(WINDOW_HEIGHT / GRID_HEIGHT);

        SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
        SDL_RenderClear(sdl_renderer);

        SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
        block.x = food.x * block.w;
        block.y = food.y * block.h;
        SDL_RenderFillRect(sdl_renderer, &block);

        SDL_SetRenderDrawColor(sdl_renderer, 0x32, 0xA8, 0x52, 0xFF);
        for(SDL_Point const &point : Snake::Instance().GetBody()){

            block.x = point.x * block.w;
            block.y = point.y * block.h;
            SDL_RenderFillRect(sdl_renderer, &block);

        }

        block.x = Snake::Instance().GetHeadPos().x * block.w;
        block.y = Snake::Instance().GetHeadPos().y * block.h;

        if(Snake::Instance().IsAlive()) SDL_SetRenderDrawColor(sdl_renderer, 0x12, 0x47, 0x20, 0xFF);
        else{
            
            SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
            EndLabel();

        }

        SDL_RenderFillRect(sdl_renderer, &block);
        SDL_RenderPresent(sdl_renderer);

    }

    void Renderer::EndLabel(){

        std::string score_text = "Your score was: " + std::to_string(Snake::Instance().Size());
        SDL_Color textColor = { 255, 255, 255, 0 };
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, score_text.c_str(), textColor);
        SDL_Texture *text = SDL_CreateTextureFromSurface(sdl_renderer, textSurface);
        SDL_Rect textRect;

        textRect.x = (WINDOW_WIDTH - textSurface -> w) * 0.5;
        textRect.y = (WINDOW_HEIGHT - textSurface -> h) * 0.5;
        textRect.w = textSurface -> w;
        textRect.h = textSurface -> h;

        SDL_RenderCopy(sdl_renderer, text, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(text);

    }

}