cmake_minimum_required(VERSION 3.20)

project(using_xtd_tunit_assert_without_tunit_app)
find_package(xtd REQUIRED)
add_sources(README.md src/using_xtd_tunit_assert_without_tunit_app.cpp)
target_type(CONSOLE_APPLICATION)
