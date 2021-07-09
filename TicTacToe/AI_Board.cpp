#include "AI_Board.h"

AI_Board::AI_Board()
{
    AI_Board::init_board();
}

void AI_Board::init_board()
{
    int count{ 1 };
    for (int i{ 0 }; i < 3; ++i)
    {
        for (int j{ 0 }; j < 3; ++j)
        {
            board[i][j] = std::to_string(count);
            count++;
        }
    }
}

void AI_Board::remove_move(const int& row, const int& col)
{
    
    board[row][col] = board_numbers[row][col];
}

//bool AI_Board::is_game_over() const
//{
//    if (check_win(Board::get_x_symbol()) || check_win(Board::get_o_symbol()))
//    {
//        return true;
//    }
//
//    for (int i{ 0 }; i < 3; ++i)
//    {
//        for (int j{ 0 }; j < 3; ++j)
//        {
//            if (board[i][j] == "&")
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}