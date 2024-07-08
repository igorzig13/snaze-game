//
// Created by igorzig13 on 23/06/24.
// Level represents "the board" of the game. It stores the state of entities like snake and food in a given moment.
//
#ifndef LEVEL_H
#define LEVEL_H

#include <cstddef>
#include <string>
#include <vector>
#include <sstream>
#include <random>

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
    explicit Cell(const size_t& line = 0, const size_t& col = 0, const e_content& content = e_content::EMPTY);
    void set_content(const e_content& content);
    [[nodiscard]] e_content get_content() const;
    [[nodiscard]] size_t get_line() const;
    [[nodiscard]] size_t get_col() const;
};

class Level {
    size_t m_lines { 10 };
    size_t m_cols { 10 };
    std::vector<Cell> m_board;
    bool valid { true };

public:
    /// Default constructor with arguments.
    explicit Level(const size_t& lines = 10, const size_t& cols = 10);
    void set_lines(const size_t& value);
    [[nodiscard]] size_t get_lines() const;
    void set_cols(const size_t& value);
    [[nodiscard]] size_t get_cols() const;
    void fill_board();
    Cell& get_cell(const size_t& r, const size_t& c);

    void update_line_from_text(const std::string& text, const size_t& line, const size_t& max_cols);
    void set_invalid();
    void clear_board();
    [[nodiscard]] bool is_valid() const;
    std::string to_string();
    void generate_food();
};

#endif //LEVEL_H
