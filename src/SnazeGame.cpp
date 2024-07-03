//
// Created by igorzig13 on 23/06/24.
//

#include "SnazeGame.h"

//=== Common methods to reading input file.
/// TODO: Add comments.
std::vector<std::string> SnazeGame::read_file_info(const std::string &filename) {
    std::vector<std::string> lines;    //!< Vector with all lines from file.
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) { lines.push_back(line); }
        file.close();
    } else {
        std::cerr << ">>> Trying to open input file [" << filename << "]..." << " error! " << std::endl;
        exit(EXIT_FAILURE);
    }

    return lines;
}

/// TODO: Add comments.
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


// === These methods are called in render()
/*!
 * Show a welcome message.
 * 
 */
void SnazeGame::display_welcome() {
    /// Display main content of this state.
    std::cout << std::endl << "---> Welcome to Snaze, v 1.0 <---" << std::endl;
    std::cout << "       -copyright UFRN 2024-" << std::endl << std::endl;
}

/*!
 * Show informations about levels found.
 * 
 */
void SnazeGame::about_levels_found() const {
    std::cout << ">>> " << m_number_of_levels << " total level(s) found at the input file, with " 
            << m_invalid_level_count << " invalid level(s)." << std::endl;
}

/// TODO: DELETE METHOD! TEST PURPOSES ONLY
void SnazeGame::print_levels() {
    TestPlayer test_player;
    m_player = &test_player;
    std::cout << std::endl << "[LEVELS]" << std::endl << std::endl;
    while (!m_levels.empty()) {
        Level current_level = m_levels.front();
        m_levels.pop();
        std::cout << current_level.to_string() << '\n';
    }
}

// === These methods are called in process_events()  
/*!
 * Read a <Enter> to continue.
 * 
 */
void SnazeGame::read_enter_to_proceed() const {
    std::cin.clear();
    std::cin.sync();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/// TODO: DELETE METHOD! TEST PURPOSES ONLY
int SnazeGame::read_option_test() {
    std::string user_menu_option_str;
    std::cin >> user_menu_option_str;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Converte a entrada de string para int
    int state_test = std::stoi(user_menu_option_str);

    return state_test;
}

//=== Common methods for the Game Loop design pattern.
/// TODO: 
void SnazeGame::initialize_game(Config &conf) {
    std::system("clear");
    m_conf = conf;
    load_config(m_conf);
}

/// TODO:
void SnazeGame::process_events() {
    if(m_state_game == game_state_e::UNDEFINED) { /* Do nothing. */ }
    else if (m_state_game == game_state_e::STARTING) { read_enter_to_proceed(); }
    else if (m_state_game == game_state_e::RUNNING) {
        option = read_option_test();
    } else if (m_state_game == game_state_e::GENERATING_FOOD) {
        /// TODO:
    } else if (m_state_game == game_state_e::CALCULATING) {
        /// TODO:
    } else if (m_state_game == game_state_e::CRASHED) {
        /// TODO:
    } else if (m_state_game == game_state_e::WON) {
        /// TODO:
    } else if (m_state_game == game_state_e::LOSE) {
        /// TODO:
    }
}

/// TODO: 
void SnazeGame::update() {
    if (m_state_game == game_state_e::UNDEFINED) {
        m_state_game = game_state_e::STARTING;
    }
    else if (m_state_game == game_state_e::STARTING) {
        m_state_game = game_state_e::RUNNING;
    } else if (m_state_game == game_state_e::GENERATING_FOOD) {
        /// TODO:
    }  else if (m_state_game == game_state_e::RUNNING) {
        /// ==== TESTS ====
        switch (option)
        {
        case 1:
            m_state_game = game_state_e::CALCULATING;
            break;
        case 2:
            m_state_game = game_state_e::CRASHED;
            break;
        case 3:
            m_state_game = game_state_e::WON;
            break;
        case 4:
            m_state_game = game_state_e::LOSE;
            break;
        case 5:
            m_state_game = game_state_e::GENERATING_FOOD;
            break;
        
        default:
            break;
        }
        /// ==== TESTS ====
    } else if (m_state_game == game_state_e::CALCULATING) {
        /// TODO:
    } else if (m_state_game == game_state_e::CRASHED) {
        /// TODO:
    } else if (m_state_game == game_state_e::WON) {
        /// TODO:
    } else if (m_state_game == game_state_e::LOSE) {
        /// TODO:
    }

}

/// TODO:
void SnazeGame::render() {
    if(m_state_game == game_state_e::UNDEFINED) { /* Do nothing. */ }
    else if(m_state_game == game_state_e::STARTING) {
        display_welcome();
        std::cout << ">>> Trying to open input file [" << m_conf.get_input_file() << "]... done!" << std::endl;
        
        about_levels_found();
        print_levels();
        
        std::cout << "Press [Enter] to continue > ";
    }
    else if(m_state_game == game_state_e::RUNNING) {
        std::system("clear");
        std::cout << "1 - CALCULATING\n";
        std::cout << "2 - CRASHED\n";
        std::cout << "3 - WON\n";
        std::cout << "4 - LOSE\n";
        std::cout << "5 - GENERATING FOOD\n";
    } else if (m_state_game == game_state_e::GENERATING_FOOD) {
        std::system("clear");
        std::cout << "GENERATING FOOD\n";
        exit(EXIT_SUCCESS);
    } else if (m_state_game == game_state_e::CALCULATING) {
        /// TODO:
        std::system("clear");
        std::cout << "CALCULATING\n";
        exit(EXIT_SUCCESS);
    } else if (m_state_game == game_state_e::CRASHED) {
        /// TODO:
        std::system("clear");
        std::cout << "CRASHED\n";
        exit(EXIT_SUCCESS);
    } else if (m_state_game == game_state_e::WON) {
        /// TODO:
        std::system("clear");
        std::cout << "WON\n";
    } else if (m_state_game == game_state_e::LOSE) {
        /// TODO:
        std::system("clear");
        std::cout << "LOSE\n";
    }
}

/*!
 * Check if the game is over.
 *
 * @return Indicate whether the game is over or not.
 * 
 */
bool SnazeGame::game_over() {
    return (m_state_game == game_state_e::WON or m_state_game == game_state_e::LOSE);
}