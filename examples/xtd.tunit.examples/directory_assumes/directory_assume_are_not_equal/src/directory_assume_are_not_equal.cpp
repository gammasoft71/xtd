#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      auto di = directory_info {environment::get_folder_path(environment::special_folder::system)};
      directory_assume::are_not_equal(directory_info {path::get_temp_path()}, di);
    }
    
    void test_method_(test_case_aborted) {
      auto di = directory_info {path::get_temp_path()};
      directory_assume::are_not_equal(directory_info {path::get_temp_path()}, di);
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
//     Test aborted
//     Expected: not "/var/folders/xg/2fvdl7v939g9kbp8xn1dpgg00000gn/T"
//     But was:  "/var/folders/xg/2fvdl7v939g9kbp8xn1dpgg00000gn/T"
//     Stack Trace: in |---OMITTED---|/directory_assume_are_not_equal.cpp:15
//
// Test results:
//   SUCCEED 1 test.
//   ABORTED 1 test.
// End 2 tests from 1 test case ran. (0 ms total)
