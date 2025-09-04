#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  // The class test must be declared with test_class_ helper.
  class test_class_(test) {
    void test_method_(test_case1) {
      auto s = string {"Hello, World!"};
      
      valid::are_equal(13, s.length());
      string_valid::starts_with("¡Hola,", s);
      string_valid::ends_with(" mundo!", s);
      assert::contains('a', s);
    }
  };
}

auto main() -> int {
  return console_unit_test().run();
}

// This code can produce the following output :
//
// Start 1 test from 1 test case
// Run tests:
//   FAILED  unit_tests::test.test_case1 (0 ms total)
//     Expected: string starting with "¡Hola,"
//     But was:  "Hello, World!"
//     Stack Trace: in |---OMITTED---|/many_valids_and_asserts.cpp:15
//   FAILED  unit_tests::test.test_case1 (0 ms total)
//     Expected: string ending with " mundo!"
//     But was:  "Hello, World!"
//     Stack Trace: in |---OMITTED---|/many_valids_and_asserts.cpp:16
//   FAILED  unit_tests::test.test_case1 (0 ms total)
//     Expected: collection containing a
//     But was:  < 'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!' >
//     Stack Trace: in |---OMITTED---|/many_valids_and_asserts.cpp:17
//
// Test results:
//   FAILED  1 test.
// End 1 test from 1 test case ran. (0 ms total)
