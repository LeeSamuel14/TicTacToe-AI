#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <memory>

#include "UI.h"

class Board
{
private:
    std::string x_symbol{ "X" };
    std::string o_symbol{ "O" };
    std::unique_ptr<UI> ui = std::make_unique<UI>();
    void init_board();
protected:
    std::string board[3][3];
    std::string board_numbers[3][3];
public:
    Board();
    const std::string get_x_symbol() const;
    const std::string get_o_symbol() const;
    void draw() const;
    void draw_vanilla() const;
    bool play(int row, int col, std::string symbol);
    bool play(int row, int col);
    bool check_win(std::string symbol) const;
    bool is_game_over() const;
    std::string get_winning_symbol() const;
    void reset();
    ~Board() = default;

};