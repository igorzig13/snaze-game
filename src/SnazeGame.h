//
// Created by igorzig13 on 23/06/24.
// Contains the gameloop related content.
//
#ifndef SNAZEGAME_H
#define SNAZEGAME_H

#include <queue>
#include <string>
#include <fstream>

#include "Level.h"
#include "Player.h"
#include "Snake.h"
#include "../init/config.h"

class SnazeGame {
    size_t m_number_of_levels{ 1 };
    size_t m_invalid_level_count { 0 };
    size_t m_total_lives { 5 };
    size_t m_food_goal { 10 };
    std::queue<Level> m_levels;
    Snake m_snake;
    Player* m_player;

public:
    void initialize_game();
    void update();
    void process_events();
    void render();
    void game_over();
    static std::vector<std::string> read_file_info(const std::string& filename);
    void load_config(Config& ini_config);

    void about_levels_found() const;

    void print_levels();

};

#endif //SNAZEGAME_H
