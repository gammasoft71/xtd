#include <xtd/xtd.tunit>

using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  // The class test must be declared with test_class_ helper.
  class test_class_(test) {
    void test_method_(test_case1) {
      auto s = "A string value";
      string_valid::are_equal_ignoring_case("A STRING VALUE", s);
    }
    
    void test_method_(test_case2) {
      auto s = "A string value";
      string_valid::contains("item", s);
    }
    
    void test_method_(test_case3) {
      auto s = "A string value";
      string_valid::matches("item$", s);
    }
  };
}

auto main() -> int {
  return console_unit_test().run();
}

// This code can produce the following output:
//
// Start 3 tests from 1 test case
// Run tests:
//   SUCCEED unit_tests::test.test_case1 (0 ms total)
//   FAILED  unit_tests::test.test_case2 (0 ms total)
//     Expected: string containing "item"
//     But was:  "A string value"
//     Stack Trace: in |---OMITTED---|/string_valid.cpp:17
//   FAILED  unit_tests::test.test_case3 (0 ms total)
//     Expected: string matching "item$"
//     But was:  "A string value"
//     Stack Trace: in |---OMITTED---|/string_valid.cpp:22
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  2 tests.
// End 3 tests from 1 test case ran. (0 ms total)
