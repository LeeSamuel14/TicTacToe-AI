#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Game.h"
#include "AI.h"


int main(int argc, char* argv[])
{
    auto game = std::make_unique<Game>();
    game->init_game();
}