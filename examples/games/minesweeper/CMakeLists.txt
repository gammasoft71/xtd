cmake_minimum_required(VERSION 3.3)

project(minesweeper)
find_package(xtd.forms REQUIRED)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE minesweeper.cpp resources/flag.xpm resources/mine.xpm resources/smiley1.xpm resources/smiley2.xpm resources/smiley3.xpm resources/smiley4.xpm)
target_link_libraries(${PROJECT_NAME} xtd.forms)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.forms/games")
