#include <xtd/xtd.tunit>
#include <vector>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      vector v = {1, 2, 3, 4};
      assert::throws<std::out_of_range>([&] {v.at(5);});
    }
    
    void test_method_(test_case_failed) {
      vector v = {1, 2, 3, 4};
      assert::throws<std::out_of_range>([&] {v.at(2);});
    }
  };
}

int main() {
  return console_unit_test().run();
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED test.test_case_succeed (0 ms total)
//   FAILED  test.test_case_failed (0 ms total)
//     Expected: <std::out_of_range>
//     But was:  <nothing>
//     Stack Trace: in |---OMITTED---|/assert_throws.cpp:15
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
