#include <xtd/xtd.tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class class_with_insert_stream_operator {
  public:
    class_with_insert_stream_operator() = default;
    explicit class_with_insert_stream_operator(int value) : value_(value) {}
    
    int value() const noexcept {return value_;}
    
    bool operator ==(const class_with_insert_stream_operator& c) const noexcept {return value_ == c.value_;}
    bool operator !=(const class_with_insert_stream_operator& c) const noexcept {return !operator ==(c);}
    
    friend std::ostream& operator <<(std::ostream& os, const class_with_insert_stream_operator& c) {
      return os << "(value = " << c.value_ << ")";
    }
    
  private:
    int value_ = 0;
  };
  
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto c1 = class_with_insert_stream_operator {42};
      auto c2 = class_with_insert_stream_operator {42};
      assert::are_equal(c1, c2);
    }
    
    void test_method_(test_case_failed) {
      auto c1 = class_with_insert_stream_operator {42};
      auto c2 = class_with_insert_stream_operator {24};
      assert::are_equal(c1, c2);
    }
  };
}

auto main() -> int {
  return console_unit_test().run();
}

// This code produces the following output :
//
// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED unit_tests::test.test_case_succeed (0 ms total)
//   FAILED  unit_tests::test.test_case_failed (0 ms total)
//     Expected: (value = 42)
//     But was:  (value = 24)
//     Stack Trace: in |---OMITTED---|/class_with_insert_stream_operator.cpp:32
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
