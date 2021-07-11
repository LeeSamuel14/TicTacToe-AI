#include "UI.h"
#include "colors.h"

void UI::color(std::string& to_color, std::string& color) const
{
    if (to_color == "light_aqua") {
        std::cout << dye::bright_white_on_green(to_color);
    }
}

void UI::color_purple(const std::string& to_color) const
{
    std::cout << dye::purple_on_black(to_color);
}

void UI::color_red(const std::string& to_color) const
{
    std::cout << dye::red_on_black(to_color);
}
void UI::color_green(const std::string& to_color) const
{
    std::cout << dye::green_on_black(to_color);
}


void UI::color(const char* to_color) const
{
    std::cout << dye::light_aqua_on_black(to_color);
}

void UI::color_symbol(const std::string& symbol) const
{
    if (symbol == "X")
    {
        std::cout << dye::light_aqua_on_black(symbol);
    }
    if (symbol == "O")
    {
        std::cout << dye::red_on_black(symbol);
    }
    if (isdigit(symbol[0]))
    {
        std::cout << dye::grey_on_black(symbol);
    }
}

void UI::intro() const
{
    std::cout << dye::light_purple_on_black(intro_text);
}

void UI::win() const
{
    std::cout << dye::black_on_light_green(win_text);
}

void UI::lose() const
{
    std::cout << dye::black_on_red(lose_text);
}

void UI::draw() const
{
    std::cout << dye::black_on_white(draw_text);
}

void UI::player_score(const int& score) const
{
    std::cout << dye::light_purple_on_black(player_score_text + std::to_string(score) + "\n");
}

void UI::pc_score(const int& score) const
{
    std::cout << dye::light_purple_on_black(pc_score_text + std::to_string(score) + "\n");
}
void UI::new_game() const
{
    std::cout << dye::light_purple_on_black(new_game_text);
}

void  UI::pc_loading() const
{
    std::cout << dye::light_purple_on_black(pc_loading_text);
}

void  UI::pc_complete() const
{
    std::cout << dye::light_purple_on_black(pc_complete_text);
}

void  UI::select_player() const
{
    std::cout << dye::light_purple_on_black(select_player_text);
}

void  UI::your_player_choice() const
{
    std::cout << dye::light_green_on_black(your_player_choice_text);
}

void  UI::invalid_selection() const
{
    std::cout << dye::red_on_black(invalid_selection_text);
}

void  UI::player_x() const
{
    std::cout << dye::light_purple_on_black(player_x_text);
}

void  UI::player_o() const
{
    std::cout << dye::light_purple_on_black(player_o_text);
}

void  UI::play_again() const
{
    std::cout << dye::light_green_on_black(play_again_text);
}

void  UI::select_number() const
{
    std::cout << dye::light_green_on_black(select_number_text);
}

void UI::your_difficulty() const
{
    std::cout << dye::light_purple_on_black(your_difficulty_text);
}

void UI::select_difficulty() const
{
    std::cout << dye::light_green_on_black(select_difficulty_text);
}
