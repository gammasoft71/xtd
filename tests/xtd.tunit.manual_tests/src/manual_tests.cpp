#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(manual_test) {
  public:
    void test_method_(test_case1) {
      assume::are_equal(10, 42);
      valid::are_equal(42, 24);
      assert::are_equal(12, 42);
      valid::are_equal(45, 24);
    }
  };
}

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
