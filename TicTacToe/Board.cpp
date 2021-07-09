#include "Board.h"
Board::Board()
{
    Board::init_board();
}

void Board::init_board()
{
    int count{ 1 };
    for (int i{ 0 }; i < 3; ++i)
    {
        for (int j{ 0 }; j < 3; ++j)
        {
            board[i][j] = std::to_string(count);
            board_numbers[i][j] = std::to_string(count);
            ++count;
        }
    }
}

/* auto Board::color(std::string s) const
{


    //border color
    return dye::aqua_on_black(s);

} */

void Board::draw() const
{
    ui->color(" ------------------------\n");
    ui->color("|       |        |       |\n");
    ui->color("|   ");
    ui->color_symbol(board[0][0]);
    ui->color("   |    ");
    ui->color_symbol(board[0][1]);
    ui->color("   |   ");
    ui->color_symbol(board[0][2]);
    ui->color("   |\n");
    ui->color("|       |        |       |\n");
    ui->color(" ------------------------\n");
    ui->color("|       |        |       |\n");
    ui->color("|   ");
    ui->color_symbol(board[1][0]);
    ui->color("   |    ");
    ui->color_symbol(board[1][1]);
    ui->color("   |   ");
    ui->color_symbol(board[1][2]);
    ui->color("   |\n");
    ui->color("|       |        |       |\n");
    ui->color(" ------------------------\n");
    ui->color("|       |        |       |\n");
    ui->color("|   ");
    ui->color_symbol(board[2][0]);
    ui->color("   |    ");
    ui->color_symbol(board[2][1]);
    ui->color("   |   ");
    ui->color_symbol(board[2][2]);
    ui->color("   |\n");
    ui->color("|       |        |       |\n");
    ui->color(" ------------------------\n");

}

void Board::draw_vanilla() const
{
    std::cout << (" ------------------------\n");
    std::cout << ("|       |        |       |\n");
    std::cout << ("|   ");
    std::cout << (board[0][0]);
    std::cout << ("   |    ");
    std::cout << (board[0][1]);
    std::cout << ("   |   ");
    std::cout << (board[0][2]);
    std::cout << ("   |\n");
    std::cout << ("|       |        |       |\n");
    std::cout << (" ------------------------\n");
    std::cout << ("|       |        |       |\n");
    std::cout << ("|   ");
    std::cout << (board[1][0]);
    std::cout << ("   |    ");
    std::cout << (board[1][1]);
    std::cout << ("   |   ");
    std::cout << (board[1][2]);
    std::cout << ("   |\n");
    std::cout << ("|       |        |       |\n");
    std::cout << (" ------------------------\n");
    std::cout << ("|       |        |       |\n");
    std::cout << ("|   ");
    std::cout << (board[2][0]);
    std::cout << ("   |    ");
    std::cout << (board[2][1]);
    std::cout << ("   |   ");
    std::cout << (board[2][2]);
    std::cout << ("   |\n");
    std::cout << ("|       |        |       |\n");
    std::cout << (" ------------------------\n");

}

bool Board::play(int row, int col, std::string symbol)
{
    std::string current_symbol{};
    if( row > -1 && row < 3 && col > -1 && col < 3)
    { 
        current_symbol = board[row][col];
    
        if (current_symbol != x_symbol && current_symbol != o_symbol)
        {
            board[row][col] = symbol; 
            return true;
        }
    }

    return false;
}

bool Board::play(int row, int col)
{
    board[row][col] = "O";
    return true;
}

bool Board::check_win(std::string symbol) const
{
    for (int i{ 0 }; i < 3; ++i)
    {
        bool row_match = (board[i][0] == symbol) && (board[i][1] == symbol) && (board[i][2] == symbol);
        bool col_match = (board[0][i] == symbol) && (board[1][i] == symbol) && (board[2][i] == symbol);

        if (row_match || col_match)
        {
            return true;
        }
    }

    bool cross_match_1 = (board[0][0] == symbol) && (board[1][1] == symbol) && (board[2][2] == symbol);
    bool cross_match_2 = (board[2][0] == symbol) && (board[1][1] == symbol) && (board[0][2] == symbol);

    if (cross_match_1 || cross_match_2)
    {
        return true;
    }

    return false;
}

bool Board::is_game_over() const
{
    if (check_win(x_symbol) || check_win(o_symbol))
    {
        return true;
    }

    for (int i{ 0 }; i < 3; ++i)
    {
        for (int j{ 0 }; j < 3; ++j)
        {
            if (isdigit((board[i][j])[0]))
            {
                return false;
            }
        }
    }
    return true;
}

std::string Board::get_winning_symbol() const
{
    if (check_win(x_symbol))
    {
        return x_symbol;
    }
    if (check_win(o_symbol))
    {
        return o_symbol;
    }
    return "-";
}

void Board::reset()
{
    Board::init_board();
}

const std::string Board::get_x_symbol() const
{
    return x_symbol;
}

const std::string Board::get_o_symbol() const
{
    return o_symbol;
}