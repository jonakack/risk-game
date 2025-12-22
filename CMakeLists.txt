cmake_minimum_required(VERSION 3.28)
project(risk-game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# set(SFML_DIR "C:/SFML-3.0.2/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS System Graphics Audio)

add_executable(risk-game 
    src/game.cpp
    src/gamestate_menu.cpp
    src/main.cpp)

target_link_libraries(risk-game PRIVATE SFML::System SFML::Graphics SFML::Audio)