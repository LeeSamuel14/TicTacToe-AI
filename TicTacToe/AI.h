#pragma once
#include <string>
#include <memory>
#include "AI_Board.h"
class AI
{
private:
public:
    int best_move_value_max{ -9999 };
    int best_move_value_min{ 9999 };
    int winning_row_max{ };
    int winning_col_max{ };
    int winning_row_min{ };
    int winning_col_min{ };
    std::unique_ptr<AI_Board> ai_board = std::make_unique<AI_Board>();
    std::unique_ptr<AI_Board> ai_board_debug = std::make_unique<AI_Board>();
    AI() = default;
    ~AI() = default;
    int get_score() const;
    int mini_max(const bool is_max, int depth);
    int play_move(const bool& is_max, int depth);
    void reset();
    void findBestMove();
};