cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.forms.manual_tests)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
add_sources("src/manual_tests.cpp")
target_default_namespace("xtd::forms::tests")
target_type(GUI_APPLICATION)
