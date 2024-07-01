//
// Created by igorzig13 on 23/06/24.
// Represents the AI engine of the game
//
#ifndef PLAYER_H
#define PLAYER_H

#include "Snake.h" // imports the Direction enum
#include "../init/config.h"

class Player {
public:
    Intelligence m_intel { Intelligence::RANDOM };

    virtual bool find_solution() = 0;
    virtual Direction next_move() = 0;
    virtual ~Player() = default;
};

class TestPlayer : public Player {
public:
    bool find_solution() override {
        return true;
    }

    Direction next_move() override {
        return Direction::FRONT;
    }
    TestPlayer() = default;
    ~TestPlayer() override = default;
};
#endif //PLAYER_H
