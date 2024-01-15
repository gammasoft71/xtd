#include <xtd/xtd.tunit>

using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case_succeed) {
      auto di = directory_info {path::get_temp_path()};
      directory_assume::exists(di);
    }
    
    void test_method_(test_case_aborted) {
      auto di = directory_info {path::combine("unknown folder 1", "unknown folder 2", "unknown folder 3")};
      directory_assume::exists(di);
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
//     Expected: directory exists
//     But was:  "unknown folder 1/unknown folder 2/unknown folder 3"
//     Stack Trace: in |---OMITTED---|/directory_assume_exists.cpp:14
//
// Test results:
//   SUCCEED 1 test.
//   ABORTED 1 test.
// End 2 tests from 1 test case ran. (0 ms total)
