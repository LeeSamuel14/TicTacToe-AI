#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <ctime>

#include "UI.h"
#include "Board.h"
#include "AI.h"

class Player
{
private:
    std::string symbol;
    unsigned int score;
    std::unique_ptr<UI> ui = std::make_unique<UI>();
public:
    Player(std::string s);
    int user_choice();
    int pc_choice();
    int get_random_number();
    std::string get_symbol() const;
    unsigned int get_score() const;
    void increment_score();
    ~Player() = default;
};