#include <xtd/tunit>

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

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}

// This code produces the following output:
//
// Start 1 test from 1 test case
// Run tests:
//   IGNORED test.test_case_aborted (0 ms total)
//     Test ignored
//
// Test results:
//   IGNORED 1 test.
// End 1 test from 1 test case ran. (0 ms total)
