#pragma once

#include <string>
#include <iostream>
#include <sstream>


class UI
{
private:
    std::string intro_text{ "WELCOME TO CONSOLE TIC TAC TOE!\n" };
    std::string win_text{ "\tYOU WIN!\n" };
    std::string lose_text{ "\tYOU LOSE\n" };
    std::string draw_text{ "\tDRAW\n" };
    std::string player_score_text{ "\nYOUR SCORE: " };
    std::string pc_score_text{ "PC SCORE: " };
    std::string new_game_text{ "\nNEW GAME!\n" };
    std::string select_player_text{ "\nSELECT A PLAYER: \n\n1 - PLAYER1\n2 - PLAYER2\n" };
    std::string your_player_choice_text{ "\nYOUR CHOICE:" };
    std::string invalid_selection_text{ "\nINVALID SELECTION: TRY AGAIN\n" };
    std::string player_x_text{ "\nYOU ARE PLAYER: X\n" };
    std::string player_o_text{ "\nYOU ARE PLAYER: O\n" };
    std::string play_again_text{ "\nPLAY AGAIN? (Y/N)\n" };
    std::string pc_loading_text{ "\nCOMPUTER THINKING...\n" };
    std::string pc_complete_text{ "\nYOUR TURN...\n" };
    std::string select_number_text{ "\nSELECT NUMBER ON BOARD:  \n" };
public:
    void color(std::string& to_color, std::string& color) const;
    void color(const std::string& to_color) const;
    void color(const char* to_color) const;
    void color_symbol(const std::string& symbol) const;
    void intro() const;
    void win() const;
    void lose() const;
    void draw() const;
    void new_game() const;
    void pc_loading() const;
    void pc_complete() const;
    void select_player() const;
    void your_player_choice() const;
    void invalid_selection() const;
    void player_x() const;
    void player_o() const;
    void play_again() const;
    void select_number() const;
    void player_score(const int& score) const;
    void pc_score(const int& score) const;
    UI() = default;
    ~UI() = default;
};
