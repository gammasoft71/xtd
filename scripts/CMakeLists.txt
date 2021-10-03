cmake_minimum_required(VERSION 3.3)

# Project
project(scripts)
include(cmake/xtd_commands.cmake)
include(cmake/xtd_version.cmake)

add_sources(
  run_tests.cmd
  run_tests.sh
)
add_sources(
  appveyor/build.cmd
  appveyor/test.cmd
)
add_sources(
  circleci/build_xtd_and_examples_on_linux.sh
  circleci/build_xtd_and_examples_on_macos.sh
  circleci/build_xtd_and_launch_coverage_on_linux.sh
  circleci/build_xtd_and_launch_unit_tests_on_linux.sh
  circleci/build_xtd_and_launch_unit_tests_on_macos.sh
  circleci/build_xtd_on_macos.sh
)
add_sources(
  cmake/update_export.cmake
  cmake/update_version_number.cmake
  cmake/xtd_commands.cmake
  cmake/xtd_version.cmake
)
add_sources(
  install/install.cmd
  install/install.sh
  install/shortcut.cmd
  install/shortcut.sh
  "install/xtd - Reference Guide.url"
)
add_sources(
  travis/build_xtd_and_examples_on_linux.sh
  travis/build_xtd_and_examples_on_macos.sh
  travis/build_xtd_and_launch_coverage_on_linux.sh
  travis/build_xtd_and_launch_unit_tests_on_linux.sh
  travis/build_xtd_and_launch_unit_tests_on_macos.sh
  travis/build_xtd_on_macos.sh
)
target_type(INTERFACE_LIBRARY)
