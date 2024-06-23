//
// Created by igorzig13 on 23/06/24.
// Contains the gameloop related content.
//

#ifndef SNAZEGAME_H
#define SNAZEGAME_H

class SnazeGame {
public:
    void initialize_game();
    void update();
    void process_events();
    void render();
    void game_over();
};

#endif //SNAZEGAME_H
