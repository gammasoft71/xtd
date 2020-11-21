#include <xtd/xtd.tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case_succeed) {
      std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
      collection_assert::all_items_are_instances_of<std::ios_base*>(a);
    }
    
    void test_method_(test_case_Failed) {
      std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
      collection_assert::all_items_are_instances_of<std::basic_ostream<char>*>(a);
    }
  };
}

int main() {
  return console_unit_test().run();
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
// Run tests:
//   SUCCEED test.test_case_succeed (0 ms total)
//   FAILED  test.test_case_Failed (0 ms total)
//     Expected: all items instance of <std::__1::basic_ostream<char, std::__1::char_traits<char> >*>
//     But was:  < 8-byte object <78-37 1D-8C FF-7F 00-00>, 8-byte object <B8-38 1D-8C FF-7F 00-00>, 8-byte object <30-36 1D-8C FF-7F 00-00> >
//     Stack Trace: in |---OMITTED---|/collection_assert_all_items_are_instances_of.cpp:13
//
// Test results:
//   SUCCEED 1 test.
//   FAILED  1 test.
// End 2 tests from 1 test case ran. (1 ms total)
