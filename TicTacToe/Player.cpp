#include "Player.h"

Player::Player(std::string s)
    : symbol{ s }, score{ 0 }
{

}

std::string Player::get_symbol() const
{
    return symbol;
}

// use Game::select_player() method if works so not taken out of game loop
/*
void Game::user_turn()
{
    bool valid_play {};
        do{
            int choice = user_player->make_choice();
            valid_play = Game::play(choice, *user_player);
        } while(!valid_play);

        board->draw();
}

void Game::pc_turn()
{
    ui->pc_loading();
    bool valid_play_pc {};
    do
    {
        int random_number = Game::get_random_number();
        valid_play_pc = Game::play(random_number, *pc_player);
    } while (!valid_play_pc);
    board->draw();
    ui->pc_complete();
}
*/
int Player::user_choice() //#lee pc vs user from ai mini-max alpha beta
{
    bool correct_input{ true };
    std::string user_input;
    do {
        ui->select_number();
        std::cin >> user_input;
        if (user_input != "1" &&
            user_input != "2" &&
            user_input != "3" &&
            user_input != "4" &&
            user_input != "5" &&
            user_input != "6" &&
            user_input != "7" &&
            user_input != "8" &&
            user_input != "9"
            )
        {
            ui->invalid_selection();
            correct_input = false;
        }
        else
        {
            correct_input = true;
        }

    } while (!correct_input);
    return std::stoi(user_input);
}

int Player::pc_choice()
{
    //AI Class need to pass board in here #lee
    return Player::get_random_number();
}

int Player::get_random_number()
{
    time_t timer{};
    const int min{ 1 };
    const int max{ 9 };
    int count{ 0 };
    srand(time(&timer));
    return rand() % (max - min + 1) + min;
}

unsigned int Player::get_score() const
{
    return score;
}

void Player::increment_score()
{
    ++score;
}