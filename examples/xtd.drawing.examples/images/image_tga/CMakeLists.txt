cmake_minimum_required(VERSION 3.20)

project(image_tga)
find_package(xtd REQUIRED)
add_sources(README.md src/image_tga.cpp)
resource(gammasoft_tga resources/gammasoft.tga)
target_type(CONSOLE_APPLICATION)
