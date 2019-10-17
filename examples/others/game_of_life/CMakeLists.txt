cmake_minimum_required(VERSION 3.3)

project(game_of_life)
find_package(xtd.forms REQUIRED)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE game_of_life.cpp cell.hpp form_main.hpp grid.hpp cell_event_args.hpp cell_event_handler.hpp)
target_link_libraries(${PROJECT_NAME} xtd.forms)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.forms/others")
