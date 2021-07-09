#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Game.h"
#include "AI.h"

void working_ai()
{
    auto ai = std::make_unique<AI>();
    /*ai->ai_board->play(0, 0, "&");
    ai->ai_board->play(0, 1, "&");
    ai->ai_board->play(0, 2, "&");

    ai->ai_board->play(1, 0, "&");
    ai->ai_board->play(1, 1, "&");
    ai->ai_board->play(1, 2, "&");

    ai->ai_board->play(2, 0, "&");
    ai->ai_board->play(2, 1, "&");
    ai->ai_board->play(2, 2, "&");*/
    ai->ai_board->draw_vanilla();
    //false if 0? I think so 
    std::cout << "thinking" << "\n";
    int row{ 0 };
    int col{ 0 };
    int count{ 0 };
    bool is_max = false;
    //for (int i = 0; i < 5; ++i)
    while (!ai->ai_board->is_game_over())
    {
        if (count == 0) {
            time_t timer{};
            const int min{ 0 };
            const int max{ 2 };
            srand(time(&timer));
            int row = rand() % (max - min + 1) + min;
            int col = rand() % (max - min + 1) + min;
            ai->ai_board->play(row, col, "O");
        }
        else {
            ai->mini_max(is_max, count);
            std::cout << ai->winning_row_min << "\n";
            std::cout << ai->winning_col_min << "\n";
            ai->ai_board->play(ai->winning_row_min, ai->winning_col_min, "O");
            ai->reset();
        }


        ai->ai_board->draw_vanilla();
        if (ai->ai_board->is_game_over()) continue;
        std::cout << "Enter row: ";
        std::cin >> row;
        std::cout << "\n";
        std::cout << "Enter col: ";
        std::cin >> col;
        ai->ai_board->play(row, col, "X");



        ai->ai_board->draw_vanilla();
        ++count;
        is_max = !is_max;

    }
    std::cout << "done";
}

int main(int argc, char* argv[])
{
   

    

    //ai->ai_board->play(1, 0, "&");

    /*ai->mini_max(true, 0);
    std::cout << ai->winning_row_max << "\n";
    std::cout << ai->winning_col_max << "\n\n\n";
    ai->ai_board->play(ai->winning_row_max, ai->winning_col_max, "O");
    ai->ai_board->draw_vanilla();*/

   /* ai->mini_max(true, 0);
    std::cout << ai->winning_row_min << "\n";
    std::cout << ai->winning_col_min << "\n";
    ai->ai_board->draw_vanilla();*/

    //ai->findBestMove();

    //working_ai();
    auto game = std::make_unique<Game>();
    game->init_game();


    /* auto ai_board = std::make_unique<AI_Board>();
    ai_board->play(0,0, "X");
    ai_board->play(0,1, "X");
    ai_board->play(0,2, "O");
    std::cout << ai_board->check_win("X");*/
    int temp{ };
    std::cin >> temp;
    return 0;
}