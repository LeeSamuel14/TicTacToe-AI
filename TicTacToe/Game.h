#pragma once
#include <memory>
#include <ctime>
#include "Player.h"
#include "Board.h"
#include "UI.h"
#include "AI.h"

class Game
{
private:
    int count{ 0 };
    bool is_max { true };
    bool first_play{ true };
    std::unique_ptr<Player> user_player;
    std::unique_ptr<Player> pc_player;
    std::unique_ptr<Board> board = std::make_unique<Board>();
    std::unique_ptr<AI> ai = std::make_unique<AI>();
    std::unique_ptr<UI> ui = std::make_unique<UI>();
    bool game_over;
    void init_game_loop();
    void init_players();
    int select_player() const;
    bool play(const int& user_choice, const Player& player);
    bool play(int row, int col);
    void user_turn();
    void pc_turn();
    void ui_players_scores() const;
    void determine_win() const;
    void clear_console() const;
public:
    Game() = default;
    void init_game();
    ~Game() = default;
};
