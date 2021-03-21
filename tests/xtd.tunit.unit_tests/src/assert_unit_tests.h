#pragma once

#include <sstream>
#include <exception>
#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include "unit_tests_event_listener.h"

#define __TUNIT_UNIT_TESTS_MODE true

namespace assert_unit_tests {
  class unit_test_error : public std::exception {
  public:
    explicit unit_test_error(const std::string& message) : message_(message) {}
    explicit unit_test_error(const char* message) : message_(message) {}
    unit_test_error(const unit_test_error&) = default;
    unit_test_error& operator=(const unit_test_error&) = default;
    const char* what() const noexcept {return message_.c_str();}
    
  private:
    std::string message_;
  };
  
  template <typename expected_t, typename actual_t>
  void assert_value(const std::string& name, const expected_t& expected, const actual_t& actual, const std::string& file, int line_number) {
    if (actual == expected)
      std::cout << "  SUCCEED " << name << std::endl;
    else {
      std::cout << "  FAILED  " << name << std::endl;
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
  
  class register_assert_unit_test {
  public:
    register_assert_unit_test(const std::string& name, std::function<void(const std::string&)> method) : method(method), name(name) {assert_unit_tests.push_back(*this);}
    register_assert_unit_test(bool ignore) {if (ignore == true) ignore_test_count++;}
    register_assert_unit_test(const register_assert_unit_test&) = default;
    register_assert_unit_test& operator=(const register_assert_unit_test&) = default;
    
    static int run_all_tests() {
      std::cout << "Start unit tests" << std::endl;
      try {
        for (auto assert_unit_test : assert_unit_tests::register_assert_unit_test::assert_unit_tests)
          assert_unit_test.method(assert_unit_test.name);
      }catch(...) {
        std::cout << "end unit tests" << std::endl;
        std::cout << std::endl << "FAILED TEST" << std::endl;
        std::cout << std::endl;
        return 1;
      }

      std::cout << "end unit tests" << std::endl;
      std::cout << std::endl << "SUCCEED " << assert_unit_tests::register_assert_unit_test::assert_unit_tests.size() << " tests." << std::endl;
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

#define assert_value_(expected, actual) assert_unit_tests::assert_value(name, expected, actual, __FILE__, __LINE__)

#define test_(class_name, function_name) \
  __##class_name##_##function_name##_unused() {} \
  void class_name##_##function_name(const std::string& name); \
  assert_unit_tests::register_assert_unit_test __##class_name##_##function_name##_name {std::string(#class_name) + "." + std::string(#function_name), &class_name##_##function_name}; \
 void class_name##_##function_name(const std::string& name)

#define ignore_test_(class_name, function_name) \
  __##class_name##_##function_name##_unused() {} \
  assert_unit_tests::register_assert_unit_test __##class_name##_##function_name##_name {true}; \
  void class_name##_##function_name(const std::string& name)
