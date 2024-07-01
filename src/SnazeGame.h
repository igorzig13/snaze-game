//
// Created by igorzig13 on 23/06/24.
// Contains the gameloop related content.
//
#ifndef SNAZEGAME_H
#define SNAZEGAME_H

#include <queue>
#include <string>
#include <fstream>
#include <limits>   

#include "Level.h"
#include "Player.h"
#include "Snake.h"
#include "../init/config.h"

class SnazeGame {
    //=== Struct
    //!< The game states.
    enum class game_state_e : short {
        UNDEFINED = 0,  //!< Only reading input file.
        STARTING,       //!< Beginning the game.
        CALCULATING,    //!< Calculating the path to food.
        RUNNING,        //!< Showing the snake animation.
        CRASHED,        //!< Error if the snake hits itself or the wall.
        WON,            //!< If the player wins.
        LOSE            //!< If the player lose.
    };

    //=== Game related members.
    size_t m_number_of_levels{ 1 };                          //!< TODO: Add comments.
    size_t m_invalid_level_count { 0 };                      //!< TODO: Add comments.
    size_t m_total_lives { 5 };                              //!< TODO: Add comments.
    size_t m_food_goal { 10 };                               //!< TODO: Add comments.
    std::queue<Level> m_levels;                              //!< TODO: Add comments.
    Snake m_snake;                                           //!< TODO: Add comments.
    Player* m_player;                                        //!< TODO: Add comments.
    game_state_e m_state_game { game_state_e::UNDEFINED };   //!< Set the current state game.
    Config m_conf;                                           //!< Set the config game.

    /// ===== TESTS
    int option {0};

public:
    //=== Common methods for the Game Loop design pattern.
    void initialize_game(Config &conf);
    /// Update the game based on the current game state.
    void update();
    /// Process user input events, depending on the current game state.
    void process_events();
    /// Renders the game to the user.
    void render();
    /// Returns true when the user wants to quit the game.
    bool game_over();

    //=== Common methods to reading input file.
    /// TODO: Add comments.
    std::vector<std::string> read_file_info(const std::string& filename);
    /// TODO: Add comments.
    void load_config(Config& ini_config);

    // === These display_xxx() methods are called in render()
    /// Show a welcome message.
    void display_welcome();
    /// Show informations about levels found.
    void about_levels_found() const;
    
    /// ========================== Tests ==================================
    /// TODO: Delete this method.
    void print_levels();
    /// TODO: Delete this method.
    int read_option_test();
    /// ========================== Tests ==================================
    
    // === These read_xxx() methods are called in process_events()  
    void read_enter_to_proceed() const;

};

#endif //SNAZEGAME_H
