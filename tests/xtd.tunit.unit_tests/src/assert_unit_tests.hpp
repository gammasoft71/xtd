#pragma once
#include <sstream>
#include <exception>
#include <iostream>
#include <functional>
#include <string>
#include <vector>

namespace assert_unit_tests {
  class unit_test_error : public std::exception {
  public:
    explicit unit_test_error(const std::string& message) : message_(message) {}
    explicit unit_test_error(const char* message) : message_(message) {}
    unit_test_error(const unit_test_error&) = default;
    unit_test_error& operator=(const unit_test_error&) = default;
    const char* what() const noexcept {return this->message_.c_str();}
    
  private:
    std::string message_;
  };
  
  template <typename TExcpected, typename TActual>
  void assert_value(const std::string& name, const TExcpected& expected, const TActual& actual, const std::string& file, int line) {
    if (actual == expected)
      std::cout << "  PASSED " << name << std::endl;
    else {
      std::cout << "  FAILED " << name << std::endl;
      std::cout << std::endl;
      std::cout << "    Expected: " << std::endl;
      std::cout << expected << std::endl;
      std::cout <<"     But was:  " << std::endl;
      std::cout << actual << std::endl;
      std::cout << file << ":" << line << std::endl;
      std::cout << std::endl;
      throw unit_test_error("assertion failed!");
    }
  }
  
  struct register_assert_unit_test {
    register_assert_unit_test(const std::string& name, std::function<void(const std::string&, int, char*[])> method) : method(method), name(name) {assert_unit_tests.push_back(*this);}
    register_assert_unit_test(const register_assert_unit_test&) = default;
    register_assert_unit_test& operator=(const register_assert_unit_test&) = default;
    
    static int run_all_tests(int argc, char* argv[]) {
      std::cout << "Start unit tests" << std::endl;
      try {
        for (auto assert_unit_test : assert_unit_tests::register_assert_unit_test::assert_unit_tests)
          assert_unit_test.method(assert_unit_test.name, argc, argv);
        std::cout << "end unit tests" << std::endl;
      }catch(...) {
        std::cout << "end unit tests" << std::endl;
        std::cout << std::endl;
        std::cout << "FAILED TEST" << std::endl;
        return 1;
      }
      return 0;
    }

    std::function<void(const std::string&, int, char*[])> method;
    std::string name;
    
    static std::vector<register_assert_unit_test> assert_unit_tests;
  };
}

#define assert_value_(expected, actual) assert_unit_tests::assert_value(name, expected, actual, __FILE__, __LINE__)

#define test_(class_name, function_name) \
  __##class_name##_##function_name##_unused() {} \
void class_name##_##function_name(const std::string& name, int argc, char* argv[]); \
assert_unit_tests::register_assert_unit_test __##class_name##_##function_name##_name {std::string(#class_name) + "." + std::string(#function_name), &class_name##_##function_name}; \
void class_name##_##function_name(const std::string& name, int argc, char* argv[])
