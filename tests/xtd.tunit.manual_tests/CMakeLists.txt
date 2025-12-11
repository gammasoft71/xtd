cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.tunit.manual_tests)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
add_sources("src/manual_tests.cpp")
target_default_namespace("xtd::tunit::tests")
target_type(TEST_APPLICATION)
