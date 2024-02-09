cmake_minimum_required(VERSION 3.20)

project(image_cur)
find_package(xtd REQUIRED)
add_sources(README.md src/image_cur.cpp)
resource(gammasoft_cur resources/gammasoft.cur)
target_type(CONSOLE_APPLICATION)
