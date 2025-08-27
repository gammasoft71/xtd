#include <xtd/xtd.tunit>

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_aborted) {
      assert::abort();
      assert::is_true(false);
    }
  };
}

auto main() -> int {
  return console_unit_test().run();
}

// This code produces the following output :
//
// Start 1 test from 1 test case
// Run tests:
//   ABORTED unit_tests::test.test_case_aborted (0 ms total)
//     Test aborted
//
// Test results:
//   ABORTED 1 test.
// End 1 test from 1 test case ran. (0 ms total)
