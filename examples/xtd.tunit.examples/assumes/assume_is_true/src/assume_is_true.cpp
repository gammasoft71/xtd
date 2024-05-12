#include <xtd/xtd.tunit>
#include <xtd/ustring>

using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto s = ustring::empty_string;
      assume::is_true(ustring::is_empty(s));
    }
    
    void test_method_(test_case_aborted) {
      auto s = "string";
      assume::is_true(ustring::is_empty(s));
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
//     Expected: true
//     But was:  false
//     Stack Trace: in |---OMITTED---|/assume_is_true.cpp:16
//
// Test results:
//   SUCCEED 1 test.
//   ABORTED 1 test.
// End 2 tests from 1 test case ran. (0 ms total)
