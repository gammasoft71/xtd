#include <xtd/xtd.tunit>

using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto di = directory_info {path::get_temp_path()};
      directory_assert::exists(di);
    }
    
    void test_method_(test_case_failed) {
      auto di = directory_info {path::combine("unknown folder 1", "unknown folder 2", "unknown folder 3")};
      directory_assert::exists(di);
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
//   FAILED  unit_tests::test.test_case_failed (0 ms total)
//     Expected: directory exists
//     But was:  "unknown folder 1/unknown folder 2/unknown folder 3"
//     Stack Trace: in |---OMITTED---|/directory_assert_exists.cpp:14
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
