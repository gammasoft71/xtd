#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      auto a = vector<ios_base*> {&cout, &cerr, &cin};
      collection_assert::all_items_are_instances_of<ios_base*>(a);
    }
    
    void test_method_(test_case_failed) {
      auto a = vector<ios_base*> {&cout, &cerr, &cin};
      collection_assert::all_items_are_instances_of<basic_ostream<char>*>(a);
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
//   FAILED  test.test_case_failed (0 ms total)
//     Expected: all items instance of <std::basic_ostream<char, std::char_traits<char> >*>
//     But was:  < 8-byte object <78-37 1D-8C FF-7F 00-00>, 8-byte object <B8-38 1D-8C FF-7F 00-00>, 8-byte object <30-36 1D-8C FF-7F 00-00> >
//     Stack Trace: in |---OMITTED---|/collection_assert_all_items_are_instances_of.cpp:13
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (1 ms total)
