#include "AI.h"

int AI::get_score() const
{
    bool is_win = (ai_board->get_winning_symbol() != "-");
    if (is_win)
    {
        if (ai_board->get_winning_symbol() == ai_board->get_x_symbol())
        {
            //std::cout << winning_row << " : ";
            //std::cout << winning_col << "  ";
            return 10;
        }
        if (ai_board->get_winning_symbol() == ai_board->get_o_symbol())
        {
            //std::cout << winning_row << " : ";
            //std::cout << winning_col << "  ";
            return -10;
        }
    }
    //a draw or no win as yet
    return 0;
}

int AI::mini_max(const bool is_max, int depth)
{
    int score = AI::get_score();

    if (score == 10)
        return 10 - depth;

    if (score == -10)
        return -10 + depth;

    if (ai_board->is_game_over())
        return 0;
    //std::cout << score;
    return AI::play_move(is_max, depth);
}

int AI::play_move(const bool& is_max, int depth)
{
    int best = is_max ? -100 : 100;
    std::string symbol = is_max ? ai_board->get_x_symbol() : ai_board->get_o_symbol();

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (!ai_board->play(i, j, symbol)) continue;

            ///best = is_max ? (  ) : (  ) ;
            if (is_max)
            {
                best = std::max(best, mini_max(!is_max, depth + 1));
                if (best > best_move_value_max) {
                    best_move_value_max = best;
                    winning_row_max = i;
                    winning_col_max = j;
                }
            }
            else {
                best = std::min(best, mini_max(!is_max, depth + 1));
                if (best < best_move_value_min) {
                    best_move_value_min = best;
                    winning_row_min = i;
                    winning_col_min = j;
                }
            }
            ai_board->remove_move(i, j);
        }
    }

    return best;
}

void AI::reset()
{
    winning_row_min = 999;
    winning_col_min = 999;
    winning_row_max = -999;
    winning_col_max = -999;
    best_move_value_min = 999;
    best_move_value_max = -999;
}

void AI::findBestMove()
{
    int bestVal = -1000;

    // Traverse all cells, evaluate minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    ai_board_debug->play(0, 0, "O");
    ai_board_debug->play(0, 1, "&");
    ai_board_debug->play(0, 2, "&");

    ai_board_debug->play(1, 0, "&");
    ai_board_debug->play(1, 1, "&");
    ai_board_debug->play(1, 2, "&");

    ai_board_debug->play(2, 0, "X");
    ai_board_debug->play(2, 1, "X");
    ai_board_debug->play(2, 2, "&");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Check if cell is empty
            if (!ai_board_debug->play(i, j, "X")) continue;
            {
                // Make the move

                // compute evaluation function for this
                // move.
                int moveVal = 0;//AI::mini_max(false);

                // Undo the move
                ai_board_debug->remove_move(i, j);

                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal)
                {
                    std::cout << i << " : ";
                    std::cout << j << "\n";
                    bestVal = moveVal;
                }
            }
        }
    }

    printf("The value of the best Move is : %d\n\n",
        bestVal);

    //return bestMove;
}