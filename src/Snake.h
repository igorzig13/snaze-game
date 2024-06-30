//
// Created by igorzig13 on 23/06/24.
// Snake represents a class with functions associated to the moving entity of the game.
//
#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Level.h"

enum class Direction {
    FRONT = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class Snake {
    Cell head_coordinate;                     //!< Location of the snake head.
    std::vector<Cell> body{};                 //!< Stores the rest of the snake body.
    size_t body_count{ 0 };                   //!< Number of cells beyond the head.
    Direction direction { Direction::FRONT};  //!< The direction the snake is facing.
};

#endif //SNAKE_H
