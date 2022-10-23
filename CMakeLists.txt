cmake_minimum_required(VERSION 3.13)
project(mini-games)

set(CMAKE_CXX_STANDART 14)
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH}})

find_package(SFML COMPONENTS graphics audio REQUIRED)

add_executable(mini-games src/main.cpp src/interface/interface.h src/interface/menu.cpp src/interface/menu.h src/game.h)
target_link_libraries(mini-games sfml-graphics sfml-audio sfml-window sfml-system)