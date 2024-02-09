cmake_minimum_required(VERSION 3.20)

project(image_bmp)
find_package(xtd REQUIRED)
add_sources(README.md src/image_bmp.cpp)
resource(gammasoft_bmp resources/gammasoft.bmp)
target_type(CONSOLE_APPLICATION)
