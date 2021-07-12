#include "Game.h"

void Game::init_game()
{
    ui->intro();
    Game::init_players();
    Game::init_difficulty();
    std::system("pause");
    Game::init_game_loop();
}

void Game::init_players()
{
    user_player = std::make_unique<Player>("X");
    pc_player = std::make_unique<Player>("O");
}

void Game::init_difficulty()
{
    int user_choice = Game::select_difficulty();
    switch (user_choice)
    {
    case 1:
    {
        difficulty = "easy";
        break;
    }
    case 2:
    {
        difficulty = "hard";
        break;
    }
    default:
        difficulty = "easy";

    }
}

void Game::init_game_loop()
{
    bool play_again{ true };
    while (play_again)
    {
        Game::clear_console();
        ui->new_game();
        ai->ai_board->draw();
        Game::ui_players_scores();
        while (!ai->ai_board->is_game_over())
        {
            if (difficulty == "easy")
            {
                Game::user_turn();
                Game::clear_console();
                if (ai->ai_board->is_game_over()) break;
                Game::pc_turn();
            }
            else
            {
                Game::pc_turn();
                Game::clear_console();
                ai->ai_board->draw();
                ui->color_red(std::string{ "PC PLAYED \nYOUR TURN\n" });
                if (ai->ai_board->is_game_over()) break;
                Game::user_turn();
            }
            
        }
        first_play = true;
        Game::determine_win();
       ai->ai_board->reset();
        std::string user_i{ };
        Game::ui_players_scores();
        ui->play_again();
        std::cin >> user_i;
        if (user_i != "y" && user_i != "Y") {
            play_again = false;
            Game::clear_console();
            Game::init_game();
        }
        else {
            Game::clear_console();
           ai->ai_board->draw();
        }
    }
}


bool Game::play(const int& choice, const Player& player)
{
    switch (choice)
    {
    case 1:
        return ai->ai_board->play(0, 0, player.get_symbol());
        break;
    case 2:
        return ai->ai_board->play(0, 1, player.get_symbol());
        break;
    case 3:
        return ai->ai_board->play(0, 2, player.get_symbol());
        break;
    case 4:
        return ai->ai_board->play(1, 0, player.get_symbol());
        break;
    case 5:
        return ai->ai_board->play(1, 1, player.get_symbol());
        break;
    case 6:
        return ai->ai_board->play(1, 2, player.get_symbol());
        break;
    case 7:
        return ai->ai_board->play(2, 0, player.get_symbol());
        break;
    case 8:
        return ai->ai_board->play(2, 1, player.get_symbol());
        break;
    case 9:
        return ai->ai_board->play(2, 2, player.get_symbol());
        break;
    default:
        return false;
        break;
    }
}

bool Game::play(int row, int col)
{
    return ai->ai_board->play(row, col);
}

int Game::select_difficulty() const
{
    bool correct_input{ true };
    std::string user_input;
    do {
        ui->select_difficulty();
        std::cin >> user_input;
        if (user_input != "1" && user_input != "2")
        {
            ui->invalid_selection();
            correct_input = false;
        }
        else
        {
            correct_input = true;
            ui->your_difficulty();
            if (user_input == "1")
                ui->color_green(std::string{ "EASY\n\n" } );
            else 
                ui->color_red(std::string{ "HARD\n\n" });

        }
    } while (!correct_input);

    return std::stoi(user_input);
}

void Game::user_turn()
{
    bool valid_play{};
    do {
        int user_choice = user_player->user_choice();
        valid_play = Game::play(user_choice, *user_player);
    } while (!valid_play);

   ai->ai_board->draw();
}

void Game::pc_turn()
{
    ui->pc_loading();
    if (difficulty == "easy")
    {
        Game::pc_easy_difficulty();
    }
    else
    {
        Game::pc_hard_difficulty();
    }

   ai->ai_board->draw();
   ui->pc_complete();
}

void Game::ui_players_scores() const
{
    ui->player_score(user_player->get_score());
    ui->pc_score(pc_player->get_score());
}

void Game::determine_win() const
{
    if (user_player->get_symbol() ==ai->ai_board->get_winning_symbol()) {
        Game::clear_console();
       ai->ai_board->draw();
        ui->win();
        ui->win();
        ui->win();
        user_player->increment_score();
    }
    else if (pc_player->get_symbol() ==ai->ai_board->get_winning_symbol()) {
        Game::clear_console();
       ai->ai_board->draw();
        ui->lose();
        ui->lose();
        ui->lose();
        pc_player->increment_score();
    }
    else {
        Game::clear_console();
       ai->ai_board->draw();
        ui->draw();
        ui->draw();
        ui->draw();
    }
}

void Game::clear_console() const
{
    std::system("cls");
}

void  Game::pc_hard_difficulty()
{
    bool valid_play_pc{ true };

    do
    {
        if (first_play)
        {
            time_t timer{};
            const int min{ 0 };
            const int max{ 2 };
            srand(time(&timer));
            int row = rand() % (max - min + 1) + min;
            int col = rand() % (max - min + 1) + min;
            ai->ai_board->play(row, col, "O");
            first_play = false;
        }
        else
        {
            ai->mini_max(is_max, 0); //count
            std::cout << ai->winning_row_min << " ";
            std::cout << ai->winning_col_min << "";
            valid_play_pc = ai->ai_board->play(ai->winning_row_max, ai->winning_col_max, "O");
            if (!valid_play_pc)
            {
                valid_play_pc = ai->ai_board->play(ai->winning_row_min, ai->winning_col_min, "O");
            }
            ai->reset();
            std::cout << "Choice Made";
            is_max = !is_max;
        }
    } while (!valid_play_pc);
}

void Game::pc_easy_difficulty()
{
    bool valid_play_pc{ true };

    do
    {
        time_t timer{};
        const int min{ 0 };
        const int max{ 2 };
        srand(time(&timer));
        int row = rand() % (max - min + 1) + min;
        int col = rand() % (max - min + 1) + min;
        valid_play_pc = ai->ai_board->play(row, col, "O");
    } while (!valid_play_pc);
}
