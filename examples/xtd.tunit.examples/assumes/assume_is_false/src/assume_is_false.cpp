#include <xtd/xtd.tunit>
#include <xtd/ustring>
#include <iterator>

using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      auto s = "string";
      assume::is_false(ustring::is_empty(s));
    }
    
    void test_method_(test_case_aborted) {
      auto s = ustring::empty_string;
      assume::is_false(ustring::is_empty(s));
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
//   ABORTED test.test_case_aborted (0 ms total)
//     Expected: false
//     But was:  true
//     Stack Trace: in |---OMITTED---|/assume_is_false.cpp:16
//
// Test results:
//   SUCCEED 1 test.
//   ABORTED 1 test.
// End 2 tests from 1 test case ran. (0 ms total)

