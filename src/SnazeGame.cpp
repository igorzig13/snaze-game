//
// Created by igorzig13 on 23/06/24.
//

#include "SnazeGame.h"

std::vector<std::string> SnazeGame::read_file_info(const std::string &filename) {
    std::vector<std::string> lines;    //!< Vector with all lines from file.
    std::ifstream file(filename);

    std::cout << ">>> Trying to open input file [" << filename << "]...";

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) { lines.push_back(line); }
        std::cout << " done!" << std::endl;
        file.close();
    } else {
        std::cerr << " error! " << std::endl;
        exit(EXIT_FAILURE);
    }

    return lines;
}

void SnazeGame::load_config(Config &ini_config) {
    std::vector<std::string> lines = read_file_info(ini_config.get_input_file());
    m_total_lives = ini_config.get_lives();
    m_food_goal = ini_config.get_food();
    m_player->m_intel = ini_config.get_playertype();
    Level aux;

    size_t level_count = 0;
    size_t current_line = 0;
    bool level_registered = false;

    for (const auto& line : lines) {
        if (std::isdigit(line[0])) {
            if (level_registered == true) {
                if (aux.is_valid())
                    m_levels.emplace(aux);
                else
                    m_invalid_level_count++;
                current_line = 0;
            }
            aux.set_lines(std::stoi(line));
            aux.set_cols(std::stoi(line.substr(line.find(' ') + 1)));
            aux.clear_board();
            aux.fill_board();

            level_count++;
            level_registered = true;
        }
        else {
            aux.update_line_from_text(line, current_line - 1, aux.get_cols());
        }
        current_line++;
    }
    if (aux.is_valid())
        m_levels.emplace(aux);
    else
        m_invalid_level_count++;

    m_number_of_levels = level_count;

}

void SnazeGame::about_levels_found() const {
    std::cout << m_number_of_levels << " total level(s) found at the input file, with " << m_invalid_level_count << " invalid level(s).\n";
}

// TODO: DELETE METHOD! TEST PURPOSES ONLY
void SnazeGame::print_levels() {
    TestPlayer test_player;
    m_player = &test_player;
    while (!m_levels.empty()) {
        Level current_level = m_levels.front();
        m_levels.pop();
        std::cout << current_level.to_string() << '\n';
    }
}
