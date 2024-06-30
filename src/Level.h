//
// Created by igorzig13 on 23/06/24.
// Level represents "the board" of the game. It stores the state of entities like snake and food in a given moment.
//
#ifndef LEVEL_H
#define LEVEL_H

#include <cstddef>
#include <vector>

enum class e_content {
    EMPTY = 0,
    WALL,
    INVISIBLE_WALL,
    FOOD,
    SNAKE_BODY,
    SNAKE_HEAD
};

class Cell {
    size_t line{ 0 };
    size_t column{ 0 };
    e_content content{ e_content::EMPTY };

public:
    /// Default constructor with arguments.
    Cell(const size_t& line, const size_t& col, const e_content& content);
};

class Level {
    size_t m_lines { 10 };
    size_t m_cols { 10 };
    std::vector<Cell> m_board;
    Cell m_start_pos;

public:
    /// Default constructor with arguments.
    Level(const size_t& lines, const size_t& cols, const Cell& pos);

private:
    void fill_board();
};

#endif //LEVEL_H
