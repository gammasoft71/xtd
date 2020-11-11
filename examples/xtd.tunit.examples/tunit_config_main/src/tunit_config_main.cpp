#define TUNIT_CONFIG_MAIN
#include <xtd/xtd.tunit>
#include <string>

using namespace xtd::tunit;

namespace unit_tests {
  // The class test must be declared with test_class_ helper.
  class test_class_(test) {
  public:
    void test_method_(test_case1) {
      std::string s = "Hello";
      assert::is_true(s == "Hello");
    }
  };
}

// This code can produce the following output:
//
// Start 1 test from 1 test case
// Run tests:
//   SUCCEED test.test_case1 (0 ms total)
//
// Test results:
//   SUCCEED 1 test.
// End 1 test from 1 test case ran. (0 ms total)
