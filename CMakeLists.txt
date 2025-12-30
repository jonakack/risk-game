cmake_minimum_required(VERSION 3.28)
project(risk-game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Set output directory for executables and resources
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# set(SFML_DIR "C:/SFML-3.0.2/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS System Graphics Audio)

add_executable(risk-game main.cpp
    src/game.cpp
    src/gamestate_europe.cpp
    src/gamestate_menu.cpp
    src/map.cpp
    src/textures.cpp)

set_target_properties(risk-game PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Copy resource folders to the output bin directory after build
add_custom_command(TARGET risk-game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/textures" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/textures"
)

target_link_libraries(risk-game PRIVATE SFML::System SFML::Graphics SFML::Audio)