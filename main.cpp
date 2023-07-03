#include "headers/Game.hpp"

int main(int argc, char **argv){

    SnakeGame::Game::Instance().Run();

    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << SnakeGame::Game::Instance().GetScore() << '\n';

    return 0;

}