#include <xtd/xtd.tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      assert::succeed();
    }
  };
}

int main() {
  return console_unit_test().run();
}

// This code produces the following output:
//
// Start 1 test from 1 test case
// Run tests:
//   SUCCEED test.test_case_succeed (0 ms total)
//
// Test results:
//   SUCCEED 1 test.
// End 1 test from 1 test case ran. (0 ms total)
