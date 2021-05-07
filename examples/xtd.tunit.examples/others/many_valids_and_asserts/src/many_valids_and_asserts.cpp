#include <xtd/xtd.tunit>
#include <string>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  // The class test must be declared with test_class_ helper.
  class test_class_(test) {
  public:
    void test_method_(test_case1) {
      string s = "Hello, World!";

      valid::are_equal_(13, s.size());
      string_valid::starts_with_("¡Hola,", s);
      string_valid::ends_with_(" mundo!", s);
      assert::contains_('a', s);
    }
  };
}

int main() {
  return console_unit_test().run();
}

// This code can produce the following output:
//
// Start 1 test from 1 test case
// Run tests:
//   FAILED  test.test_case1 (0 ms total)
//     Expected: string starting with "¡Hola,"
//     But was:  "Hello, World!"
//     Stack Trace: in |---OMITTED---|/many_valids_and_asserts.cpp:15
//   FAILED  test.test_case1 (0 ms total)
//     Expected: string ending with " mundo!"
//     But was:  "Hello, World!"
//     Stack Trace: in |---OMITTED---|/many_valids_and_asserts.cpp:16
//   FAILED  test.test_case1 (0 ms total)
//     Expected: collection containing a
//     But was:  < 'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!' >
//     Stack Trace: in |---OMITTED---|/many_valids_and_asserts.cpp:17
//
// Test results:
//   FAILED  1 test.
// End 1 test from 1 test case ran. (0 ms total)
