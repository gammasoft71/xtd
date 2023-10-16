cmake_minimum_required(VERSION 3.20)

project(image_pnm)
find_package(xtd REQUIRED)
add_references(xtd.drawing)
add_sources(README.md src/image_pnm.cpp)
resource(gammasoft_pnm resources/gammasoft.pnm)
target_type(CONSOLE_APPLICATION)
