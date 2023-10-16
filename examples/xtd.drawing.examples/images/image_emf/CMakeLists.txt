cmake_minimum_required(VERSION 3.20)

project(image_emf)
find_package(xtd REQUIRED)
add_references(xtd.drawing)
add_sources(README.md src/image_emf.cpp)
resource(gammasoft_emf resources/gammasoft.emf)
target_type(CONSOLE_APPLICATION)
