#include <xtd/xtd.tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_ignored) {
      assert::ignore();
      assert::is_true(false);
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
//   IGNORED test.test_case_ignored (0 ms total)
//     Test ignored
//
// Test results:
//   IGNORED 1 test.
// End 1 test from 1 test case ran. (0 ms total)
