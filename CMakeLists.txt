set(CMAKE_CXX_STANDARD  14)
cmake_minimum_required(VERSION 3.20)

project(snake)
add_executable(snake main.cpp CGame.cpp CGame.h CScreen.h CScreen.cpp CSnake.cpp CSnake.h SCoord.cpp SCoord.h)
