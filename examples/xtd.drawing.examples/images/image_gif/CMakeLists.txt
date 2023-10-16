cmake_minimum_required(VERSION 3.20)

project(image_gif)
find_package(xtd REQUIRED)
add_references(xtd.drawing)
add_sources(README.md src/image_gif.cpp)
resource(gammasoft_gif resources/gammasoft.gif)
target_type(CONSOLE_APPLICATION)
