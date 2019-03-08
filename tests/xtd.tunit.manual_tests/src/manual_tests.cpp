#include <xtd/tunit>

using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(manual_test) {
  public:
    void test_method_(test_case1) {
      int i1 = 0, i2 = 3;
      std::vector<int*> a = {&i1, &i2, nullptr};
      collection_assert::all_items_are_not_null(a);
    }
  };
}

int main(int argc, char* argv[]) {
  return console_unit_test(argv, argc).run();
}
