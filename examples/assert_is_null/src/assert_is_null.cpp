#include <xtd/tunit>
#include <memory>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      shared_ptr<string> s;
      assert::is_null_(s);
    }

    void test_method_(test_case_failed) {
      shared_ptr<string> s = make_shared<string>("string");
      assert::is_null_(s);
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
//     PASSED test_case_succeed (0 ms total)
//     FAILED test_case_failed (0 ms total)
//
// Expected: null
// But was:  not null
// error: !---OMITTED---!/xtd.tunit/examples/assert_are_equal/src/assert_is_null.cpp:18
//
//   End 2 tests from test (0 ms total)
//
//   Summary :
//     PASSED 1 test.
// *** FAILED 1 test, listed below:
// *** FAILED test.test_case_failed
//
//     FAILED 1 test.
// End 2 tests from 1 test case ran. (0 ms total)

