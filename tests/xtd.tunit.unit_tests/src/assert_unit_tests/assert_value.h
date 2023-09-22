#pragma once

#include "unit_test_error.h"
#include <xtd/foreground_color>
#include <xtd/reset_color>
#include <iostream>
#include <sstream>
#include <string>

namespace assert_unit_tests {
  template <typename expected_t, typename actual_t>
  void assert_value(const std::string& name, const expected_t& expected, const actual_t& actual, const std::string& file, int line_number) {
    if (actual == expected)
      std::cout << xtd::foreground_color(xtd::console_color::dark_green) << "  SUCCEED " << xtd::reset_color() << name << std::endl;
    else {
      std::cout << xtd::foreground_color(xtd::console_color::dark_red) << "  FAILED  " << xtd::reset_color() << name << std::endl;
      std::cout << "    Expected:" << std::endl;
      std::stringstream f;
      f << expected;
      std::string line;
      while (std::getline(f, line))
        std::cout << "      " << line << std::endl;
      std::cout << "    But was:" << std::endl;
      f.str("");
      f.clear();
      f << actual;
      while (std::getline(f, line))
        std::cout << "      " << line << std::endl;
      std::cout << "    Stack trace:" << std::endl;
      std::cout << "      " << file << ":" << line_number << std::endl;
      throw unit_test_error("assertion failed!");
    }
  }
}

#define assert_value_(expected, actual) \
  assert_unit_tests::assert_value(name, expected, actual, __FILE__, __LINE__)

#define assert_value_(expected, actual) \
  assert_unit_tests::assert_value(name, expected, actual, __FILE__, __LINE__)
