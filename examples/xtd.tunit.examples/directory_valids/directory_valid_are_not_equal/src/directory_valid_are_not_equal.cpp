#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto di = directory_info {environment::get_folder_path(environment::special_folder::system)};
      directory_valid::are_not_equal(directory_info {path::get_temp_path()}, di);
    }
    
    void test_method_(test_case_failed) {
      auto di = directory_info {path::get_temp_path()};
      directory_valid::are_not_equal(directory_info {path::get_temp_path()}, di);
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
//   FAILED  unit_tests::test.test_case_failed (0 ms total)
//     Expected: not "/var/folders/xg/2fvdl7v939g9kbp8xn1dpgg00000gn/T"
//     But was:  "/var/folders/xg/2fvdl7v939g9kbp8xn1dpgg00000gn/T"
//     Stack Trace: in |---OMITTED---|/directory_valid_are_not_equal.cpp:15
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)
