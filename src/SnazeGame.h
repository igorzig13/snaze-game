//
// Created by igorzig13 on 23/06/24.
// Contains the gameloop related content.
//
#ifndef SNAZEGAME_H
#define SNAZEGAME_H

#include <queue>
#include "Level.h"
#include "Player.h"
#include "Snake.h"

class SnazeGame {
    size_t number_of_levels{ 1 };
    std::queue<Level> levels;
    Snake snake;
    Player player;

public:
    void initialize_game();
    void update();
    void process_events();
    void render();
    void game_over();

private:
    void set_levels();
    void set_snake();
    void set_player();
};

#endif //SNAZEGAME_H
