//
// Created by igorzig13 on 23/06/24.
// Represents the AI engine of the game
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Snake.h" // imports the Direction enum

class Player {

    bool find_solution();
    Direction next_move();
};

#endif //PLAYER_H
