//
// Created by igorzig13 on 23/06/24.
//

#include "Level.h"

/// Cell default constructor
Cell::Cell(const size_t& line, const size_t& col, const e_content& content)
: line(line), column(col), content(content) {}

void Cell::set_content(const e_content& content) {
    this->content = content;
}

e_content Cell::get_content() const {
    return this->content;
}

size_t Cell::get_line() const {
    return this->line;
}

size_t Cell::get_col() const {
    return this->column;
}

/// Level default constructor;
Level::Level(const size_t &lines, const size_t &cols)
: m_lines(lines), m_cols(cols){}

void Level::set_lines(const size_t& value) {
    this->m_lines = value;
}

size_t Level::get_lines() const {
    return this->m_lines;
}

void Level::set_cols(const size_t& value) {
    this->m_cols = value;
}

size_t Level::get_cols() const {
    return this->m_cols;
}

void Level::fill_board() {
    for (int i = 0; i < m_lines; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            this->m_board.emplace_back(i, j, e_content::EMPTY);
        }
    }
}

Cell& Level::get_cell(const size_t &r, const size_t &c) {
    const size_t index = r * get_cols() + c;
    return m_board[index];
}

void Level::update_line_from_text(const std::string &text, const size_t& line, const size_t& max_cols) {
    size_t col = 0;
    for (const auto& c : text) {
        switch (c) {
            case '#':
                this->get_cell(line, col).set_content(e_content::WALL);
                break;
            case '&':
                this->get_cell(line, col).set_content(e_content::SNAKE_HEAD);
                break;
            case '.':
                this->get_cell(line,col).set_content(e_content::INVISIBLE_WALL);
                break;
            case ' ':
                this->get_cell(line, col).set_content(e_content::EMPTY);
                break;
            default:
                this->set_invalid();
                break;
        }
        col++;
    }
}

void Level::set_invalid() {
    this->valid = false;
}

void Level::clear_board() {
    this->m_board.clear();
}

bool Level::is_valid() const {
    return this->valid;
}

// TODO: EDIT METHOD, CURRENT VERSION FOR TEST PURPOSES.
std::string Level::to_string() {
    std::ostringstream oss;
    for (size_t i = 0; i < m_lines; ++i) {
        for (size_t j = 0; j < m_cols; ++j) {
            if (get_cell(i, j).get_content() == e_content::WALL) {
                oss << "#";
            } else if (get_cell(i, j).get_content() == e_content::EMPTY ||
                get_cell(i, j).get_content() == e_content::INVISIBLE_WALL) {
                oss << " ";
            } else if (get_cell(i, j).get_content() == e_content::FOOD) {
                oss << "F";
            }
            else {
                oss << "S";
            }
        }
        oss << "\n";
    }
    return oss.str();
}

void Level::generate_food() {
    std::vector<Cell> empty_cells;

    for (auto& cell : this->m_board) {
        if (cell.get_content() == e_content::EMPTY) {
            empty_cells.push_back(cell);
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, empty_cells.size() - 1);
    const size_t random_index = dis(gen);

    const size_t line_to_update = empty_cells[random_index].get_line();
    const size_t col_to_update = empty_cells[random_index].get_line();
    this->get_cell(line_to_update, col_to_update).set_content(e_content::FOOD);
}


