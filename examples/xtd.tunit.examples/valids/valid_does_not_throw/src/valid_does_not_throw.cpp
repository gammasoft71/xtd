#include <xtd/xtd.tunit>
#include <vector>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      auto v = vector {1, 2, 3, 4};
      valid::does_not_throw([&] {return v.at(2);});
    }
    
    void test_method_(test_case_failed) {
      auto v = vector {1, 2, 3, 4};
      valid::does_not_throw([&] {return v.at(5);});
    }
  };
}

auto main()->int {
  return console_unit_test().run();
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED test.test_case_succeed (0 ms total)
//   FAILED  test.test_case_failed (0 ms total)
//     Expected: No Exception to be thrown
//     But was:  <std::out_of_range>
//     Stack Trace: in |---OMITTED---|/valid_does_not_throw.cpp:15
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
