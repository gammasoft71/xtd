cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.drawing.rounded_rectangles.tests)
include("../../../scripts/cmake/xtd_commands.cmake")
include("../../../scripts/cmake/xtd_version.cmake")
add_sources("src/rounded_rectangles.cpp")
target_default_namespace("xtd::drawing::tests")
target_type(GUI_APPLICATION)
