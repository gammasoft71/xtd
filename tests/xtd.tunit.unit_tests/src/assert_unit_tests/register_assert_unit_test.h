#pragma once

#include "unit_tests_event_listener.h"
#include <xtd/tunit/settings>
#include <xtd/tunit/unit_test>
#include <xtd/foreground_color>
#include <xtd/reset_color>
#include <iostream>
#include <functional>
#include <sstream>
#include <string>
#include <vector>

namespace assert_unit_tests {
  class register_assert_unit_test {
  public:
    register_assert_unit_test(const std::string& name, std::function<void(const std::string&)> method) : method(method), name(name) {assert_unit_tests.push_back(*this);}
    register_assert_unit_test(bool ignore) {if (ignore == true) ignore_test_count++;}
    register_assert_unit_test(const register_assert_unit_test&) = default;
    register_assert_unit_test& operator =(const register_assert_unit_test&) = default;
    
    static std::pair<std::string, int> run_test(const std::string& filter_tests) {
      xtd::tunit::settings::default_settings().exit_status(0);
      xtd::tunit::settings::default_settings().filter_tests({filter_tests});
      auto output_stream = std::stringstream {};
      auto result = xtd::tunit::unit_test(std::make_unique<unit_tests_event_listener>(output_stream)).run();
      return std::make_pair(output_stream.str(), result);
    }
    
    static int run_all_tests() {
      std::cout << "Start unit tests" << std::endl;
      try {
        for (auto assert_unit_test : assert_unit_tests::register_assert_unit_test::assert_unit_tests)
          assert_unit_test.method(assert_unit_test.name);
      } catch (...) {
        std::cout << "end unit tests" << std::endl;
        std::cout << std::endl << xtd::foreground_color(xtd::console_color::dark_red) << "FAILED TEST" << xtd::reset_color() << std::endl;
        std::cout << std::endl;
        return 1;
      }
      
      std::cout << "end unit tests" << std::endl;
      std::cout << std::endl << xtd::foreground_color(xtd::console_color::dark_green) << "SUCCEED " << xtd::reset_color() << assert_unit_tests::register_assert_unit_test::assert_unit_tests.size() << " tests." << std::endl;
      if (ignore_test_count) std::cout << std::endl << "You have " << ignore_test_count << " ignored test" << (ignore_test_count < 2 ? "" : "s") << std::endl;
      std::cout << std::endl;
      return 0;
    }
    
    std::function<void(const std::string&)> method;
    std::string name;
    
    static std::vector<register_assert_unit_test> assert_unit_tests;
    static size_t ignore_test_count;
  };
}

#define init_test_(filter_tests) \
  assert_unit_tests::register_assert_unit_test::init_test(filter_tests)

#define run_test_(filter_tests) \
  assert_unit_tests::register_assert_unit_test::run_test(filter_tests)

#define test_(class_name, function_name) \
  __##class_name##_##function_name##_unused() {} \
  void class_name##_##function_name(const std::string& name); \
  assert_unit_tests::register_assert_unit_test __##class_name##_##function_name##_name {std::string(#class_name) + "." + std::string(#function_name), &class_name##_##function_name}; \
  void class_name##_##function_name(const std::string& name)

#define ignore_test_(class_name, function_name) \
  __##class_name##_##function_name##_unused() {} \
  assert_unit_tests::register_assert_unit_test __##class_name##_##function_name##_name {true}; \
  void class_name##_##function_name(const std::string& name)
