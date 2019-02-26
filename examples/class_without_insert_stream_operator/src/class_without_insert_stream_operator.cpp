#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class class_without_insert_stream_operator {
  public:
  public:
    class_without_insert_stream_operator() = default;
    explicit class_without_insert_stream_operator(int value) : value_(value) {}
    
    int value() const noexcept {return this->value_;}
    
    bool operator==(const class_without_insert_stream_operator& c) const noexcept {return this->value_ == c.value_;}
    bool operator!=(const class_without_insert_stream_operator& c) const noexcept {return !this->operator==(c);}

  private:
    int value_ = 0;
  };
  
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      class_without_insert_stream_operator c1(42);
      class_without_insert_stream_operator c2(42);
      assert::are_equal_(c1, c2);

    }

    void test_method_(test_case_failed) {
      class_without_insert_stream_operator c1(42);
      class_without_insert_stream_operator c2(24);
      assert::are_equal_(c1, c2);
    }
  };
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}

// This code produces the following output:
//
/// tart 2 tests from 1 test case
//   Start 2 tests from test
//     SUCCEED test_case_succeed (0 ms total)
//     FAILED  test_case_failed (0 ms total)
//
// Expected: 4-byte object <2A-00 00-00>
// But was:  4-byte object <18-00 00-00>
// error: !---OMITTED---!/xtd.tunit/examples/assert_are_equal/src/class_without_insert_stream_operator.cpp:33
//
//   End 2 tests from test (0 ms total)
//
//   Summary :
//     SUCCEED 1 test.
//     FAILED  1 test, listed below:
//     FAILED  test.test_case_failed
//
//     FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)

