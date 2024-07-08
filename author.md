# Introduction

This project should be a Snake game with a twist: the snake is trapped in a maze. Unfortunately it is not functional (playable) yet, despite being runnable.

# Authors:

* IGOR MARQUES DE LIMA
* VITOR EMANUEL RODRIGUES DE ALENCAR

# Difficulties and Grading Expectations

It was very challenging to find time to this project in particular so the current version does not implement the game as specified in the docs, and the repository is just a way to see the source code and the directions it was going to, expect lots of TODOs in the files.

# What you CAN do in this version
You can provide levels to be read and the program should be fully able to load the levels found in the file,
also telling the user how many of the levels in the file were invalid. The levels will be shown in the order they were read and then you will be presented with a menu.
Option 5 in the menu is functional and will successfully generate a piece of food in a random empty location of the board.
The starting point of the Snake is presented with the letter `S` and the food by the letter `F`.

# Compiling and Running

### Using CMake
To compile the project using CMake, from the root folder, execute:
`
cmake -S . -B build

The compilation generates an executable named `snaze` inside the `build/` directory.
To execute the program, use the command:

`
./build/snaze
`
The default configuration file path is `config/snaze.ini`. If you face any trouble with the file, consider editing the path at the 11th line in main.cpp:

`conf.load("../config/snaze.ini"); `