cmake_minimum_required(VERSION 3.28)
project(snaze)

set(CMAKE_CXX_STANDARD 17)

add_executable(snaze main.cpp
        src/Snake.cpp
        src/Snake.h
        src/Level.cpp
        src/Level.h
        src/Player.cpp
        src/Player.h
        src/SnazeGame.cpp
        src/SnazeGame.h)
