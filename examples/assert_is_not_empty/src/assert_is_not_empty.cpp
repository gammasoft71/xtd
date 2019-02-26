#include <xtd/tunit>
#include <list>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_collection_succeed) {
      list l = {0, 1, 2, 3};
      assert::is_not_empty_(l);
    }
    
    void test_method_(test_case_collection_failed) {
      list<int> l;
      assert::is_not_empty_(l);
    }
    
    void test_method_(test_case_string_succeed) {
      string s = "string";
      assert::is_not_empty_(s);
    }
    
    void test_method_(test_case_string_failed) {
      string s;
      assert::is_not_empty_(s);
    }
  };
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}

// This code produces the following output:
//
// Start 4 tests from 1 test case
//   Start 4 tests from test
//     SUCCEED test_case_collection_succeed (0 ms total)
//     FAILED  test_case_collection_failed (0 ms total)
//
// Expected: collection not <empty>
// But was:  <empty>
// error: !---OMITTED---!/xtd.tunit/examples/assert_contains/src/assert_is_not_empty.cpp:17
//
//     SUCCEED test_case_string_succeed (0 ms total)
//     FAILED  test_case_string_failed (0 ms total)
//
// Expected: collection not <empty>
// But was:  <empty>
// error: !---OMITTED---!/xtd.tunit/examples/assert_contains/src/assert_is_not_empty.cpp:27
//
//   End 4 tests from test (0 ms total)
//
//   Summary :
//     SUCCEED 2 tests.
// *** FAILED  2 tests, listed below:
// *** FAILED  test.test_case_collection_failed
// *** FAILED  test.test_case_string_failed
//
//     FAILED  2 tests.
// End 4 tests from 1 test case ran. (0 ms total)
