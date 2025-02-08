#pragma once
#include "unit_test_error.hpp"
#include <xtd/diagnostics/source_location>
#include <xtd/foreground_color>
#include <xtd/reset_color>
#include <iostream>
#include <sstream>
#include <string>

namespace assert_unit_tests {
  template<class expected_t, class actual_t>
  void assert_value(const std::string& name, const expected_t& expected, const actual_t& actual, const xtd::diagnostics::source_location& location = xtd::diagnostics::source_location::current()) {
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
      std::cout << "      " << location.file_name() << ":" << location.line() << std::endl;
      throw unit_test_error("assertion failed!");
    }
  }
}

#define assert_value_(expected, actual) \
  assert_unit_tests::assert_value(name, expected, actual)
