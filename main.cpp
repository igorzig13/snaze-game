#include <iostream>

#include "init/config.h"
#include "src/SnazeGame.h"

int main() {
    // Call major game functions here.

    // ================= Test functions =====================
    Config conf;
    conf.load("../config/snaze.ini");

    /*std::cout << "Config settings:" << std::endl;
    std::cout << "Input file: " << conf.get_input_file() << std::endl;
    std::cout << "FPS: " << conf.get_fps() << std::endl;
    std::cout << "Lives: " << conf.get_lives() << std::endl;
    std::cout << "Food: " << conf.get_food() << std::endl;
    std::cout << "Player type: " 
              << (conf.get_playertype() == Intelligence::RANDOM ? "RANDOM" : "BACKTRACK") 
              << std::endl;*/

    SnazeGame snaze_game;

    snaze_game.load_config(conf);
    snaze_game.about_levels_found();
    snaze_game.print_levels();
    return 0;
}
