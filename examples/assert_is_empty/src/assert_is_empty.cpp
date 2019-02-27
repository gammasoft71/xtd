#include <xtd/tunit>
#include <list>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_collection_succeed) {
      list<int> l;
      assert::is_empty(l);
    }
    
    void test_method_(test_case_collection_failed) {
      list l = {0, 1, 2, 3};
      assert::is_empty(l);
    }
    
    void test_method_(test_case_string_succeed) {
      string s;
      assert::is_empty(s);
    }
    
    void test_method_(test_case_string_failed) {
      string s = "string";
      assert::is_empty(s);
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
// Run tests:
//   SUCCEED test.test_case_collection_succeed (0 ms total)
//   FAILED  test.test_case_collection_failed (0 ms total)
//     Expected: collection <empty>
//     But was:  < 0, 1, 2, 3 >
//     Stack Trace: in |---OMITTED---|/xtd/xtd.tunit/examples/assert_is_empty/src/assert_is_empty.cpp:15
//   SUCCEED test.test_case_string_succeed (0 ms total)
//   FAILED  test.test_case_string_failed (0 ms total)
//     Expected: collection <empty>
//     But was:  < 's', 't', 'r', 'i', 'n', 'g' >
//     Stack Trace: in |---OMITTED---|/xtd/xtd.tunit/examples/assert_is_empty/src/assert_is_empty.cpp:25
//
// Test results:
//   SUCCEED 2 tests.
//   FAILED  2 tests.
// End 4 tests from 1 test case ran. (0 ms total)
