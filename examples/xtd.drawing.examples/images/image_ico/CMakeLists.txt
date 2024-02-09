cmake_minimum_required(VERSION 3.20)

project(image_ico)
find_package(xtd REQUIRED)
add_sources(README.md src/image_ico.cpp)
resource(gammasoft_ico resources/gammasoft.ico)
target_type(CONSOLE_APPLICATION)
