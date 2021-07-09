#pragma once 
#include <string>
#include "Board.h"
class AI_Board : public Board
{
private:
    void init_board();
public:
    AI_Board();
    void remove_move(const int&, const int&);
    //bool is_game_over() const;
};