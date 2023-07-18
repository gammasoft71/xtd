cmake_minimum_required(VERSION 3.3)

project(bit_converter)
find_package(xtd REQUIRED)

add_projects(
  bit_converter
  bit_converter_endianness
  bit_converter_is_big_endian
  bit_converter_is_little_endian
  bit_converter_round_trips
)
