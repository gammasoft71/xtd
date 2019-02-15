#include <xtd/tunit>
#include <iostream>
#include <stdexcept>
#include <thread>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  // The class test must be declared with test_class_ helper.
  class test_class_(version_test) {
  public:
    void test_method_(test_case1) {
      string s = "Hello, World!";
      assert::are_equal("Hello, World!", s);
    }
    
    void test_method_(test_case2) {
      bool b = true;
      assert::are_equal(true, b);
    }
    
    void ignore_test_method_(test_case3) {
      int i = 42;
      assert::are_equal(42, i);
    }
  };

  // The class test must be declared with test_class_ helper.
  class test_class_(uri_test) {
  public:
    void test_method_(test_case1) {
      bool b = true;
      assert::are_equal_(false, b);
    }
  };
}

void dump() {
  throw std::invalid_argument("");
}

int main(int argc, char* argv[]) {
  console_unit_test unit_test(argv, argc);
  settings::default_settings().also_run_ignored_tests(true);
  return unit_test.run();
}
