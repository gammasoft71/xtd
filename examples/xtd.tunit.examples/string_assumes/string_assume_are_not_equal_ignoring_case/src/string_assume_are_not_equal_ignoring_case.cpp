#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto s = u"VALUE"_s;
      string_assume::are_not_equal_ignoring_case(u"key", s);
    }
    
    void test_method_(test_case_aborted) {
      auto s = U"VALUE"_s;
      string_assume::are_not_equal_ignoring_case(U"value", s);
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
//   SUCCEED unit_tests::test.test_case_succeed (0 ms total)
//   ABORTED test.test_case_aborted (0 ms total)
//     Test aborted
//     Expected: not "value", ignoring case
//     But was:  "VALUE"
//     Stack Trace: in |---OMITTED---|/string_assume_are_equal_ignoring_case.cpp:16
//
// Test results:
//   SUCCEED 1 test.
//   ABORTED 1 test.
// End 2 tests from 1 test case ran. (0 ms total)
