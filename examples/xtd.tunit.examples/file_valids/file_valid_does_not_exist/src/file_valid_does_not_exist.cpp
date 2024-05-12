#include <xtd/xtd.tunit>

using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto fn = path::get_temp_file_name();
      file::remove(fn);
      file_valid::does_not_exist(fn);
    }
    
    void test_method_(test_case_failed) {
      auto fn = path::get_temp_file_name();
      file_valid::does_not_exist(fn);
      file::remove(fn);
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
//     Expected: not file exists
//     But was:  "/var/folders/xg/2fvdl7v939g9kbp8xn1dpgg00000gn/T/tmp80d41b2c.tmp"
//     Stack Trace: in |---OMITTED---|/file_valid_does_not_exist.cpp:15
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
