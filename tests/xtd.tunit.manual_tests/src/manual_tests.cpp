#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class base_test : public test_class {
  public:
    void test_method_(base_test_case1) {
      string_assert::are_equal_ignoring_case("hello", "HELLO");
    }
  };
  
  class test_class_from_(test, base_test) {
  public:
    void test_method_(test_case1) {
    }
  };
}

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
