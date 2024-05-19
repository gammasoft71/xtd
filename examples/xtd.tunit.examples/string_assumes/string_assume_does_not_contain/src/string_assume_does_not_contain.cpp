#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto s = "value"_s;
      string_assume::does_not_contain("zor", s);
    }
    
    void test_method_(test_case_aborted) {
      auto s = L"value";
      string_assume::does_not_contain(L"alu", s);
    }
  };
}

auto main() -> int {
  return console_unit_test().run();
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED unit_tests::test.test_case_succeed (0 ms total)
//   ABORTED test.test_case_aborted (0 ms total)
//     Test aborted
//     Expected: not string containing "alu"
//     But was:  "value"
//     Stack Trace: in |---OMITTED---|/string_assume_does_not_contain.cpp:16
//
// Test results:
//   SUCCEED 1 test.
//   ABORTED 1 test.
// End 2 tests from 1 test case ran. (0 ms total)
