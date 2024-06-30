//
// Created by igorzig13 on 23/06/24.
//

#include "Level.h"

/// Cell default constructor
Cell::Cell(const size_t& line = 0, const size_t& col = 0, const e_content& content = e_content::EMPTY)
: line(line), column(col), content(content) {}

/// Level default constructor;
Level::Level(const size_t &lines, const size_t &cols, const Cell &pos)
: m_lines(lines), m_cols(cols), m_start_pos(pos) {
    fill_board();
}

void Level::fill_board() {
    for (int i = 0; i < m_lines; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            this->m_board.emplace_back(i, j, e_content::EMPTY);
        }
    }
}


