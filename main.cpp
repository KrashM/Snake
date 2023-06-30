#include <iostream>
#include "headers/Game.hpp"
#include "headers/Renderer.hpp"

int main(int argc, char **argv){

    SnakeGame::Renderer renderer;
    SnakeGame::Controller controller;
    SnakeGame::Game game;
    game.Run(controller, renderer);

    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << game.GetScore() << '\n';

    return 0;

}