#pragma once
#include <exception>
#include <string>

namespace assert_unit_tests {
  class unit_test_error : public std::exception {
  public:
    explicit unit_test_error(const std::string& message) : message_(message) {}
    explicit unit_test_error(const char* message) : message_(message) {}
    unit_test_error(const unit_test_error&) = default;
    unit_test_error& operator =(const unit_test_error&) = default;
    const char* what() const noexcept {return message_.c_str();}
    
  private:
    std::string message_;
  };
}
