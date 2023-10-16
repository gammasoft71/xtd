cmake_minimum_required(VERSION 3.20)

project(image_pcx)
find_package(xtd REQUIRED)
add_references(xtd.drawing)
add_sources(README.md src/image_pcx.cpp)
resource(gammasoft_pcx resources/gammasoft.pcx)
target_type(CONSOLE_APPLICATION)
