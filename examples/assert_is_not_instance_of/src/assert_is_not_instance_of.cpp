#include <xtd/tunit>
#include <stdexcept>
#include <string>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      invalid_argument except("invalid argument");
      assert::is_not_instance_of_(bad_cast, except);
    }

    void test_method_(test_case_failed) {
      invalid_argument except("invalid argument");
      assert::is_not_instance_of_(logic_error, except);
    }
  };
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}

// This code produces the following output:
//
/// tart 2 tests from 1 test case
//   Start 2 tests from test
//     SUCCEED test_case_succeed (0 ms total)
//     FAILED  test_case_failed (0 ms total)
//
// Expected: not instance of <std::logic_error>
// But was:  <std::invalid_argument>
// error: !---OMITTED---!/xtd.tunit/examples/assert_are_equal/src/assert_is_not_instance_of.cpp:18
//
//   End 2 tests from test (0 ms total)
//
//   Summary :
//     SUCCEED 1 test.
//     FAILED  1 test, listed below:
//     FAILED  test.test_case_failed
//
//     FAILED  1 test.
// End 2 tests from 1 test case ran. (0 ms total)

