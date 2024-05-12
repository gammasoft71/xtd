#include <xtd/xtd.tunit>
#include <stdexcept>

using namespace std;
using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  // The class test must be declared with test_class_ helper.
  class test_class_(test) {
    void test_method_(test_case1) {
      auto fn = path::get_temp_file_name();
      file_valid::exists(fn);
      file::remove(fn);
    }
    
    void test_method_(test_case2) {
      auto fn = path::get_random_file_name();
      file_valid::exists(fn);
      // No need to remove fn because the file does not exist.
    }
    
    void test_method_(test_case3) {
      auto is = istringstream {"xtd::tunit::file_valid::are_equal example."};
      file_valid::are_equal(istringstream {"xtd::tunit::file_valid::are_equel example."}, is);
    }
  };
}

auto main()->int {
  return console_unit_test().run();
}

// This code can produce the following output:
//
// Start 3 tests from 1 test case
// Run tests:
//   SUCCEED unit_tests::test.test_case1 (0 ms total)
//   FAILED  unit_tests::test.test_case2 (0 ms total)
//     Expected: file exists
//     But was:  "t35uk5my.8v2"
//     Stack Trace: in |---OMITTED---|/file_valid.cpp:18
//   FAILED  unit_tests::test.test_case3 (0 ms total)
//     Expected: istream at offset 31 value e
//     But was:  a
//     Stack Trace: in |---OMITTED---|/file_valid.cpp:24
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  2 tests.
// End 3 tests from 1 test case ran. (0 ms total)
